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

/*
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
*/

static sfBool update_key_event(hero_t *hero, sfEvent *event, sfEventType type)
{
    sfKeyCode codes[4] = { sfKeyDown , sfKeyLeft, sfKeyRight, sfKeyUp };
    enum player_move move[4] = { PLAYER_MOVE_DOWN, PLAYER_MOVE_LEFT,
        PLAYER_MOVE_RIGHT, PLAYER_MOVE_UP };

    if (event->type != type)
        return (sfFalse);
    for (u8_t i = 0; i < ARRAY_SIZE(codes); i++) {
        if (event->key.code == codes[i]) {
            hero->move[move[i]] = (type == sfEvtKeyPressed);
            return (sfTrue);
        }
    }
    return (sfFalse);
}

bool handle_hero_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    hero_t *hero = entity->instance;

    if (update_key_event(hero, event, sfEvtKeyPressed) == sfFalse)
        update_key_event(hero, event, sfEvtKeyReleased);
    return (false);
}