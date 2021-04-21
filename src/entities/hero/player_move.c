/*
** EPITECH PROJECT, 2021
** player
** File description:
** move
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/window.h"
#include "SFML/Window.h"
#include "myrpg/asset.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/define.h"
#include "stdlib.h"
#include "distract/debug.h"
#include "distract/util.h"
#include "myrpg/util.h"
#include "distract/input.h"

static bool player_move(hero_t *hero, sfIntRect *rect, sfKeyCode move)
{
    int anim[4] = { 83, 166, 249, 0};
    void (*moves[4])(hero_t *, sfIntRect *) = {
        player_move_left, player_move_right, player_move_up, player_move_down
    };

    rect->top= anim[move];
    if (rect->left > 300)
        rect->left = 0;
    if (hero->animation_clock->time >= 0.10f) {
        rect->left += 45;
        if (rect->left == 135)
            rect->left = 0;
        hero->animation_clock->time = 0;
    }
    if (hero->movement_clock->time >= 0.010f) {
        moves[move](hero, rect);
        hero->movement_clock->time = 0;
    }
    sfSprite_setTextureRect(hero->sprite, *rect);
    return (true);
}

void update_hero_move(game_t *game, hero_t *hero)
{
    sfIntRect rect = sfSprite_getTextureRect(hero->sprite);

    for (sfKeyCode code = START_ARROW_KEY; code <= END_ARROW_KEY; code++) {
        if (IS_KEY_DOWN(code)) {
            player_move(hero, &rect, code - START_ARROW_KEY);
            trigger_battle_rand(game, hero);
            return;
        }
    }
}