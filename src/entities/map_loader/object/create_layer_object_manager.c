/*
** EPITECH PROJECT, 2020
** layer_object_manager
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
#include "myrpg/map/map.h"
#include "distract/util.h"

bool create_layer_object_manager(game_t *game UNUSED, entity_t *entity)
{
    layer_object_manager_t *layer_object_manager = dcalloc(
        sizeof(layer_object_manager_t), 1);
    ig_map_t map = {0};

    D_ASSERT(load_map_from_file(game, &map), false, "", false);
    D_ASSERT(layer_object_manager, NULL, "Could not init layer"
        " object manager", false);
    if (load_layers_object(game, &layer_object_manager, &map) == false) {
        print_error("Failed to load layer object manager");
        return (false);
    }
    layer_object_manager->entity = entity;
    entity->instance = layer_object_manager;
    return (true);
}

void destroy_layer_object_manager(game_t *game UNUSED, entity_t *entity)
{
    layer_object_manager_t *layer_object_manager = entity->instance;

    if (layer_object_manager->layer)
        layer_object_manager->layer->clear(&layer_object_manager->layer);
    free(layer_object_manager);
}