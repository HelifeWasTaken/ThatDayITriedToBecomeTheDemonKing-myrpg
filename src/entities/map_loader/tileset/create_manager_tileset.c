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

bool create_tileset_manager(game_t *game UNUSED, entity_t *entity)
{
    tileset_manager_t *tileset_manager = dcalloc(sizeof(tileset_manager_t), 1);
    ig_map_t mapconf = {0};

    D_ASSERT(tileset_manager, NULL, "Could not init tileset manager", false);
    D_ASSERT(load_map_from_file(game, &mapconf), false, "", false);
    if ((load_tileset(game, &mapconf, tileset_manager) == false) {
        destroy_iron_goat_map(&mapconf);
        return (false);
    }
    destroy_iron_goat_map(&mapconf);
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