/*
** EPITECH PROJECT, 2021
** bard_talking
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/game.h"
#include "distract/resources.h"
#include "erty/estdlib.h"
#include "myrpg/asset.h"
#include "myrpg/battle.h"
#include "myrpg/entities.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <stdlib.h>

static const char *BARD_DIALOGS[] = {
    "i can't lose, not today",
    "i won't lose, not today",
    "you will never win",
    "i will not desist",
    "you don't know my power",
    "i'm the best bard of the town",
    "i can fight as many enemies as there is",
    "i can sing for you if you desist",
    "i will not take any aggro",
    "i will play guitar at your death",
    "you shall not attack me",
    "you will face consequences",
    "what makes you think you can do this",
    "approach me, and i will attack",
    "do i look powerless?",
    "i am powerful, beyond imagination",
    "do not try to overthrow me, you can't",
    "never try to fight me",
    "you can't best me",
    "i can't be beat",
    "i am the toughest opponent",
    "this will be your last day on earth",
    "do not resist, just desist"
};

static void build_text(battlemanager_t *battlemanager, sfFont *font)
{

    sfText_setFont(battlemanager->bard_talking, font);
    sfText_setColor(battlemanager->bard_talking, sfWhite);
    sfText_setCharacterSize(battlemanager->bard_talking, 20);
    sfText_scale(battlemanager->bard_talking, VEC2F(0.25, 0.25));
    set_battle_bard_text(battlemanager, get_battle_random_bard_dialog());
}

void set_battle_bard_text(battlemanager_t *battlemanager, const char *text)
{
    sfFloatRect sprite_rect = sfSprite_getGlobalBounds(
        battlemanager->friends[0].animable_info.sprite);
    sfFloatRect text_rect = sfText_getGlobalBounds(battlemanager->bard_talking);
    sfText_setPosition(battlemanager->bard_talking,
        VEC2F(sprite_rect.left + sprite_rect.width / 2 - text_rect.width / 2,
            sprite_rect.top - 10));
    sfText_setString(battlemanager->bard_talking, text);
}

int create_battle_bard_talking(game_t *game, battlemanager_t *battlemanager)
{
    sfFont *font;

    battlemanager->bard_talking = sfText_create();
    D_ASSERT(battlemanager->bard_talking, NULL,
        "Could not create battle manager bard text", -1)
    battlemanager->bard_talking_clock = create_pausable_clock(game);
    D_ASSERT(battlemanager->bard_talking_clock, NULL,
        "Could not create battle manager bard clock", -1)
    font = create_font(game, FONT);
    D_ASSERT(font, NULL, "Could not create battle manager bard font", -1)
    build_text(battlemanager, font);
    return (0);
}

const char *get_battle_random_bard_dialog(void)
{
    return (BARD_DIALOGS[rand() % ARRAY_SIZE(BARD_DIALOGS)]);
}

