/*
** EPITECH PROJECT, 2021
** battlemanager
** File description:
** Source code
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

bool create_battlemanager(game_t *game UNUSED, entity_t *entity)
{
    battlemanager_t *battlemanager = dcalloc(sizeof(battlemanager_t), 1);
    sfIntRect rect = IRECT(0, 0, 9133, 379);
    sfTexture *texture = create_texture(game, "assets/sprite.png", &rect);

    D_ASSERT(battlemanager, NULL, "Could not create battle manager", false)
    battlemanager->entity = entity;
    battlemanager->clock = create_pausable_clock(game);
    battlemanager->sprite = create_sprite(texture, NULL);
    entity->instance = battlemanager;
}

void destroy_battlemanager(game_t *game UNUSED, entity_t *entity)
{
    battlemanager_t *battlemanager = entity->instance;

    sfSprite_destroy(battlemanager->sprite);
    destroy_pausable_clock(battlemanager->clock);
    free(battlemanager);
}

void update_battlemanager(game_t *game UNUSED, entity_t *entity)
{
    battlemanager_t *battlemanager = entity->instance;

    sfSprite_setPosition(battlemanager->sprite, entity->pos);
    tick_pausable_clock(battlemanager->clock);
}

void draw_battlemanager(game_t *game UNUSED, entity_t *entity)
{
    battlemanager_t *battlemanager = entity->instance;

    sfRenderWindow_drawSprite(game->window, battlemanager->sprite, NULL);
}

bool handle_battlemanager_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    return (false);
}