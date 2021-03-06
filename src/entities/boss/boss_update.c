/*
** EPITECH PROJECT, 2020
** pnj
** File description:
** Entity
*/

#include "distract/math.h"
#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#undef ABS
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/pnj.h"
#include "myrpg/battle.h"
#include "myrpg/util.h"
#include <SFML/System/Vector2.h>

static void update_animation(boss_t *boss)
{
    sfIntRect rect;

    for (usize_t i = 0; i < boss->boss_vector->size; i++) {
        rect = sfSprite_getTextureRect(boss->boss_vector->data[i].sprite);
        rect.left += boss->boss_vector->data[i].rect_size.x;
        if (rect.left == (int)(boss->boss_vector->data[i].rect_size.x *
            (boss->boss_vector->data[i].frame)))
            rect.left = 0;
        sfSprite_setTextureRect(boss->boss_vector->data[i].sprite, rect);
        boss->boss_vector->data[i].pos = sfSprite_getPosition(
            boss->boss_vector->data[i].sprite);
    }
}

void update_boss(game_t *game UNUSED, entity_t *entity)
{
    boss_t *boss = entity->instance;
    boss_data_t *data;
    sfVector2f pos;
    game_state_t *state = game->state;

    for (usize_t i = 0; i < boss->boss_vector->size; i++) {
        data = &boss->boss_vector->data[i];
        pos = v2fadd(data->pos, VEC2F(
            data->rect_size.x / 2,
            data->rect_size.y / 2));
        if (data->trigger_battle
            && !state->save.levels_done[data->boss_id]
            && v2fdistance(&boss->hero->entity->pos, &pos) < 70)
            start_battle(game, data->boss_id);
    }
    tick_pausable_clock(boss->clock);
    if (boss->clock->time > 0.25) {
        update_animation(boss);
        restart_pausable_clock(boss->clock);
    }
}

void draw_boss(game_t *game UNUSED, entity_t *entity)
{
    usize_t i = 0;
    boss_t *boss = entity->instance;
    game_state_t *state = game->state;
    boss_data_t *boss_data;

    for (; i < boss->boss_vector->size; i++) {
        boss_data = &boss->boss_vector->data[i];
        if (!state->save.levels_done[boss_data->boss_id])
            sfRenderWindow_drawSprite(game->window,
                boss_data->sprite, NULL);
    }
}
