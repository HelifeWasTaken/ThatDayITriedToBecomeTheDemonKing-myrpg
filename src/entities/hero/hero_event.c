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

static const int MOVE_SPEED = 5;

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
        hero->animation_clock->time = 0;
    }
    sfSprite_setTextureRect(hero->sprite, rect);
    return (true);
}

static bool player_move(hero_t *hero, int anim, sfIntRect rect)
{
    rect.top = anim;
    if (rect.left > 300) {
        rect.left = 0;
    }
    if (hero->animation_clock->time >= 0.10f) {
        rect.left += 45;
        if (rect.left == 135)
            rect.left = 0;
        hero->animation_clock->time = 0;
    }
    if (hero->movement_clock->time >= 0.020f) {
        anim == 0 ? try_player_movement_down(hero, &VEC2F(0, MOVE_SPEED), rect) : 0;
        anim == 83 ? try_player_movement_left(hero, &VEC2F(-MOVE_SPEED, 0), rect) : 0;
        anim == 166 ? try_player_movement_right(hero, &VEC2F(MOVE_SPEED, 0), rect) : 0;
        anim == 249 ? try_player_movement_up(hero, &VEC2F(0, -MOVE_SPEED), rect): 0;
        hero->movement_clock->time = 0;
    }
    sfSprite_setTextureRect(hero->sprite, rect);
    return (true);
}

bool handle_hero_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    hero_t *hero = entity->instance;
    sfIntRect rect = sfSprite_getTextureRect(hero->sprite);

    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        return (player_anim(hero));
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
        return (player_move(hero, 0, rect));
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        return (player_move(hero, 83, rect));
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        return (player_move(hero, 166, rect));
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        return (player_move(hero, 249, rect));
    return (false);
}
