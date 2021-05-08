/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_text
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"

bool create_text_quest(game_t *game, entity_t *entity)
{
    quest_menu_t *quest = entity->instance;
    sfFont *font = create_font(game, FONT);
    sfFloatRect rect = sfSprite_getGlobalBounds(quest->sprite);

    D_ASSERT(font, NULL, "err", false);
    quest->back = sfText_create();
    D_ASSERT(quest->back, NULL, "error back text", false);
    quest->text = sfText_create();
    sfText_setFont(quest->text, font);
    D_ASSERT(quest->text, NULL, "error text", false);
    sfText_setFont(quest->back, font);
    sfText_setString(quest->back, "X");
    sfText_setScale(quest->back, VEC2F(1.10, 1.10));
    sfText_setString(quest->text, TEXT);
    sfText_setPosition(quest->text, VEC2F(quest->entity->pos.x + 20,
        quest->entity->pos.y + 20));
    sfText_setPosition(quest->back, VEC2F(rect.width + 600,
        rect.height));
    return (true);
}