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

static bool player_move(hero_t *hero, sfIntRect *rect,
    enum player_move move, game_t *game)
{
    int anim[4] = { 0, 83, 166, 249 };
    void (*moves[4])(hero_t *, sfIntRect *, game_t *) = {
        player_move_down, player_move_left, player_move_right, player_move_up
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
        moves[move](hero, rect, game);
        hero->movement_clock->time = 0;
    }
    sfSprite_setTextureRect(hero->sprite, *rect);
    return (true);
}

void update_hero_move(game_t *game UNUSED, hero_t *hero)
{
    sfIntRect rect = sfSprite_getTextureRect(hero->sprite);

    for (int i = 0; i < PLAYER_MOVE_END; i++) {
        if (hero->move[i] == sfTrue) {
            player_move(hero, &rect, i, game);
            return;
        }
    }
}