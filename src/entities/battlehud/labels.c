/*
** EPITECH PROJECT, 2021
** buttons
** File description:
** Source code
*/

#include "distract/entity.h"
#include "distract/debug.h"
#include "erty/eprintf.h"
#include "erty/estdlib.h"
#include "erty/string/ecstring.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>
#include "stdlib.h"

static bool fill_labels(game_t *game UNUSED, battlehud_t *hud)
{
    sfVector2f pos = hud->entity->pos;

    hud->hp_label->entity->pos = VEC2F(pos.x + 750, pos.y + 50);
    hud->hp_label->title = estrdup("HP:   XXX");
    hud->lv_label->entity->pos = VEC2F(pos.x + 750, pos.y + 100);
    hud->lv_label->title = estrdup("Lv.   XXX");
    hud->mana_label->entity->pos = VEC2F(pos.x + 750, pos.y + 150);
    hud->mana_label->title = estrdup("Mana: XXX");
    D_ASSERT(hud->lv_label->title, NULL, "Cannot stralloc battlehud", false);
    D_ASSERT(hud->mana_label->title, NULL, "Cannot stralloc battlehud", false);
    D_ASSERT(hud->hp_label->title, NULL, "Cannot stralloc battlehud", false);
    return (true);
}

static int count_digits(int nb, int max)
{
    int count = 1;

    if (nb < 0)
        nb = -nb;
    while (nb >= 10) {
        nb /= 10;
        count++;
    }
    return (max < count ? max : count);
}

bool create_battlehud_labels(game_t *game, battlehud_t *hud)
{
    entity_t *tmp;
    
    tmp = create_entity(game, GUI_LABEL);
    D_ASSERT(tmp, NULL, "Cannot create battlehud labels", false);
    hud->hp_label = tmp->instance;
    tmp = create_entity(game, GUI_LABEL);
    D_ASSERT(tmp, NULL, "Cannot create battlehud labels", false);
    hud->lv_label = tmp->instance;
    tmp = create_entity(game, GUI_LABEL);
    D_ASSERT(tmp, NULL, "Cannot create battlehud labels", false);
    hud->mana_label = tmp->instance;
    return (fill_labels(game, hud));
}

void update_battlehub_labels(game_t *game UNUSED, battlehud_t *hud UNUSED)
{
    game_state_t *state = game->state;
    char *base = "0123456789";
    int offset_lv = 6 + (3 - count_digits(state->save.player_lv, 3));
    int offset_hp = 6 + (3 - count_digits(state->save.player_hp, 3));
    int offset_mana = 6 + (3 - count_digits(state->save.player_mana, 3));

    ememset(hud->lv_label->title + 6, ' ', 3);
    ememset(hud->hp_label->title + 6, ' ', 3);
    ememset(hud->mana_label->title + 6, ' ', 3);
    eitoa(state->save.player_lv, hud->lv_label->title + offset_lv, base);
    eitoa(state->save.player_hp, hud->hp_label->title + offset_hp, base);
    eitoa(state->save.player_mana, hud->mana_label->title + offset_mana, base);
}

void destroy_battlehud_labels(game_t *game UNUSED, battlehud_t *hud)
{
    free(hud->hp_label->title);
    free(hud->lv_label->title);
    free(hud->mana_label->title);
}