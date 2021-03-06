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
#include "myrpg/battle.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>
#include "stdlib.h"

static bool fill_labels(game_t *game UNUSED, battlehud_t *hud)
{
    sfVector2f pos = hud->entity->pos;

    hud->lv_label->entity->pos = VEC2F(pos.x + 900, pos.y + 125);
    hud->lv_label->title = estrdup("Lv.   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    hud->hp_label->entity->pos = VEC2F(pos.x + 900, pos.y + 175);
    hud->hp_label->title = estrdup("HP:   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    hud->xp_label->entity->pos = VEC2F(pos.x + 900, pos.y + 225);
    hud->xp_label->title = estrdup("XP:   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    D_ASSERT(hud->lv_label->title, NULL, "Cannot stralloc battlehud", false);
    D_ASSERT(hud->xp_label->title, NULL, "Cannot stralloc battlehud", false);
    D_ASSERT(hud->hp_label->title, NULL, "Cannot stralloc battlehud", false);
    return (true);
}

static int count_digits(int nb, int max)
{
    int count = 1;

    if (nb < 0) {
        nb = -nb;
        count++;
    }
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
    hud->xp_label = tmp->instance;
    return (fill_labels(game, hud));
}

void update_battlehub_labels(game_t *game UNUSED, battlehud_t *hud UNUSED)
{
    game_state_t *state = game->state;
    char *base = "0123456789";
    battle_opponent_t *opponent = &hud->manager->friends[0];
    int offset_lv = 5 + (4 - count_digits(opponent->level, 3));
    int offset_hp = 5 + (4 - count_digits(opponent->health, 3));
    int offset_xp = 5 + (4 - count_digits(state->save.player_xp, 3));

    D_ASSERT((offset_lv < 0 || offset_lv > 8), true, "Invalid level", (void)0)
    D_ASSERT((offset_hp < 0 || offset_hp > 8), true, "Invalid hp", (void)0)
    D_ASSERT((offset_xp < 0 || offset_xp > 8), true, "Invalid xp", (void)0)
    ememset(hud->lv_label->title + 5, ' ', 34);
    ememset(hud->hp_label->title + 5, ' ', 34);
    ememset(hud->xp_label->title + 5, ' ', 34);
    eitoa(opponent->level, hud->lv_label->title + offset_lv, base);
    eitoa(opponent->health, hud->hp_label->title + offset_hp, base);
    eitoa(state->save.player_xp, hud->xp_label->title + offset_xp, base);
}

void destroy_battlehud_labels(game_t *game UNUSED, battlehud_t *hud)
{
    free(hud->hp_label->title);
    free(hud->lv_label->title);
    free(hud->xp_label->title);
}