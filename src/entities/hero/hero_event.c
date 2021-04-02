/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** hero_event.c
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "stdio.h"
#include "myrpg/define.h"
#include "distract/debug.h"
#include "myrpg/util.h"

#error Need to move player anim
static bool player_anim(hero_t *hero)
{
    sfIntRect rect = sfSprite_getTextureRect(hero->sprite);

    if (rect.left < 900) {
        rect.left = 900;
        rect.top = 100;
    }
    if (hero->animation_clock->time >= 0.20f) {
        rect.left += 100;
        if (rect.left == 1200)
            rect.left = 900;
    }
    sfSprite_setTextureRect(hero->sprite, rect);
    return (true);
}

static bool player_move(hero_t *hero, sfIntRect *rect, enum player_move move)
{
    int anim[4] = { 0, 83, 166, 249 };
    void (*moves[4])(hero_t *, sfIntRect *) = { player_move_down,
        player_move_left, player_move_right, player_move_up };

    rect->top= anim[move];
    if (rect->left > 300)
        rect->left = 0;
    if (hero->animation_clock->time >= 0.10f) {
        rect->left += 45;
        if (rect->left == 135)
            rect->left = 0;
        hero->animation_clock->time = 0;
    }
    if (hero->movement_clock->time >= 0.020f) {
        moves[move](hero, rect);
        hero->movement_clock->time = 0;
    }
    sfSprite_setTextureRect(hero->sprite, *rect);
    return (true);
}

bool handle_hero_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    hero_t *hero = entity->instance;
    sfIntRect rect = sfSprite_getTextureRect(hero->sprite);
    sfKeyCode codes[4] = { sfKeyDown , sfKeyLeft, sfKeyRight, sfKeyUp };
    enum player_move move[4] = { PLAYER_MOVE_DOWN, PLAYER_MOVE_LEFT,
        PLAYER_MOVE_RIGHT, PLAYER_MOVE_UP };

    for (u8_t i = 0; i < ARRAY_SIZE(codes); i++) {
        if (sfKeyboard_isKeyPressed(codes[i]) == sfTrue) {
            return (player_move(hero, &rect, move[i]));
        }
    }
    return (false);
}
