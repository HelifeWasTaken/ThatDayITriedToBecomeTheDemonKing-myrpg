/*
** EPITECH PROJECT, 2020
** tileset_manager
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
#include "distract/util.h"
#include "myrpg/state.h"

bool create_tileset_manager(game_t *game UNUSED, entity_t *entity)
{
    tileset_manager_t *tileset_manager = dcalloc(sizeof(tileset_manager_t), 1);
    game_state_t *state = game->state;

    D_ASSERT(tileset_manager, NULL, "Could not init tileset manager", false);
    if (load_tileset(game, &state->map, tileset_manager) == false)
        return (false);
    tileset_manager->entity = entity;
    entity->instance = tileset_manager;
    return (true);
}

void destroy_tileset_manager(game_t *game UNUSED, entity_t *entity)
{
    tileset_manager_t *tileset_manager = entity->instance;

    tileset_manager->tileset->clear(&tileset_manager->tileset);
    free(tileset_manager);
}