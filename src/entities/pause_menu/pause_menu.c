/*
** EPITECH PROJECT, 2020
** pause_menu
** File description:
** Entity
*/

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

bool create_pause_menu(game_t *game UNUSED, entity_t *entity)
{
    pause_menu_t *pause_menu = dcalloc(sizeof(pause_menu_t), 1);
    sfIntRect rect = IRECT(0, 0, 9133, 379);
    sfTexture *texture = create_texture(game, BG_PAUSE, &rect);

    D_ASSERT(pause_menu, NULL, texture, false);
    D_ASSERT(texture, NULL, texture, false);
    pause_menu->entity = entity;
    pause_menu->clock = create_pausable_clock(game);
    pause_menu->sprite = create_sprite(texture, NULL);
    D_ASSERT(pause_menu->sprite, NULL, "error bg pause", false);
    entity->instance = pause_menu;
}

void destroy_pause_menu(game_t *game UNUSED, entity_t *entity)
{
    pause_menu_t *pause_menu = entity->instance;

    sfSprite_destroy(pause_menu->sprite);
    destroy_pausable_clock(pause_menu->clock);
    free(pause_menu);
}

void update_pause_menu(game_t *game UNUSED, entity_t *entity)
{
    pause_menu_t *pause_menu = entity->instance;

    sfSprite_setPosition(pause_menu->sprite, entity->pos);
    tick_pausable_clock(pause_menu->clock);
}

void draw_pause_menu(game_t *game UNUSED, entity_t *entity)
{
    pause_menu_t *pause_menu = entity->instance;

    sfRenderWindow_drawSprite(game->window, pause_menu->sprite, NULL);
}

bool handle_pause_menu_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    return (false);
}