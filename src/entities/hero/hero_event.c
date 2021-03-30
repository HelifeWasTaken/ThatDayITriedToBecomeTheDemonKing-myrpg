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

/* static bool player_anim(hero_t *hero)
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
} */

static bool player_move(hero_t *hero, int anim, sfIntRect rect)
{
    rect.top = anim;
    if (rect.left > 300) {
        rect.left = 0;
    }
    if (hero->animation_clock->time >= 0.10f) {
        rect.left += 100;
        if (rect.left == 300)
            rect.left = 0;
        hero->animation_clock->time = 0;
    }
    if (hero->movement_clock->time >= 0.020f) {
        anim == 0 ? hero->entity->pos.y += 8 : 0;
        anim == 100 ? hero->entity->pos.x -= 8 : 0;
        anim == 200 ? hero->entity->pos.x += 8 : 0;
        anim == 300 ? hero->entity->pos.y -= 8 : 0;
        hero->movement_clock->time = 0;
    }
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

    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyUp)
            hero->key[KEY_UP] = true;
        if (event->key.code == sfKeyRight)
            hero->key[KEY_RIGHT] = true;
        if (event->key.code == sfKeyLeft)
            hero->key[KEY_LEFT] = true;
        if (event->key.code == sfKeyDown)
            hero->key[KEY_DOWN] = true;
    }
    for (int i = 0; i < 4; i++) {
        if (hero->key[i] == true)
            player_move(hero, HERO_KEY[i],rect);
    }
    check_key_not_pressed(hero, event);
    return (false);
}