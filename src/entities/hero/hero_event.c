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

bool player_move(hero_t *hero, int anim)
{
    sfIntRect rest = sfSprite_getTextureRect(hero->sprite);

    rest.top = anim;
    if (hero->animation_clock->time >= 0.10f) {
        rest.left += 100;
        if (rest.left == 300)
            rest.left = 0;
        hero->animation_clock->time = 0;
    }
    if (hero->movement_clock->time >= 0.005f) {
        anim == 0 ? hero->entity->pos.y += 8 : 0;
        anim == 100 ? hero->entity->pos.x -= 8 : 0;
        anim == 200 ? hero->entity->pos.x += 8 : 0;
        anim == 300 ? hero->entity->pos.y -= 8 : 0;
        hero->movement_clock->time = 0;
    }
    sfSprite_setTextureRect(hero->sprite, rest);
    return (true);
}

bool handle_hero_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    hero_t *hero = entity->instance;
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
        return (player_move(hero, 0));
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        return (player_move(hero, 100));
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        return (player_move(hero, 200));
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
        return (player_move(hero, 300));
    return (false);
}