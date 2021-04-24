/*
** EPITECH PROJECT, 2020
** battledummy
** File description:
** Entity
*/

#include "distract/animable.h"
#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "distract/util.h"
#include <SFML/Graphics/Sprite.h>

bool create_battledummy(game_t *game UNUSED, entity_t *entity)
{
    battledummy_t *battledummy = dcalloc(sizeof(battledummy_t), 1);

    D_ASSERT(battledummy, NULL, "Could not create battle entity", false)
    battledummy->entity = entity;
    battledummy->clock = create_pausable_clock(game);
    battledummy->sprite = create_sprite(NULL, NULL);
    entity->instance = battledummy;
    return (true);
}

void destroy_battledummy(game_t *game UNUSED, entity_t *entity)
{
    battledummy_t *battledummy = entity->instance;

    sfSprite_destroy(battledummy->sprite);
    destroy_pausable_clock(battledummy->clock);
    free(battledummy);
}

void update_battledummy(game_t *game UNUSED, entity_t *entity)
{
    battledummy_t *battledummy = entity->instance;
    animable_t *anim = &battledummy->animable;
    
    if (battledummy->clock->time > 0.4f) {
        if (is_animation_done(anim)) {
            set_animable_animation(anim, 2);
        } else {
            set_animable_frame(anim, get_animable_frame(anim) + 1);
        }
        battledummy->clock->time = 0;
    }
    sfSprite_setPosition(battledummy->sprite, entity->pos);
    tick_pausable_clock(battledummy->clock);
}

void draw_battledummy(game_t *game UNUSED, entity_t *entity)
{
    battledummy_t *battledummy = entity->instance;

    sfRenderWindow_drawSprite(game->window, battledummy->sprite, NULL);
}

bool handle_battledummy_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    return (false);
}