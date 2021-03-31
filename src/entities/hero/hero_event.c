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

void vector_aug(hero_t *hero, int anim)
{
    if (hero->movement_clock->time >= 0.020f) {
        anim == 0 ? hero->entity->pos.y += 8 : 0;
        anim == 83 ? hero->entity->pos.x -= 8 : 0;
        anim == 166 ? hero->entity->pos.x += 8 : 0;
        anim == 249 ? hero->entity->pos.y -= 8 : 0;
        hero->movement_clock->time = 0;
    }
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
    vector_aug(hero, anim);
    sfSprite_setTextureRect(hero->sprite, rect);
    return (true);
}

void check_key_not_pressed(hero_t *hero, sfEvent *event)
{
    if (event->type == sfEvtKeyReleased) {
        if (event->key.code == sfKeyUp)
            hero->key[KEY_UP] = false;
        if (event->key.code == sfKeyRight)
            hero->key[KEY_RIGHT] = false;
        if (event->key.code == sfKeyLeft)
            hero->key[KEY_LEFT] = false;
        if (event->key.code == sfKeyDown)
            hero->key[KEY_DOWN] = false;
    }
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