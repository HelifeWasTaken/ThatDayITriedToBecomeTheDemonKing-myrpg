/*
** EPITECH PROJECT, 2020
** map_loader
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
#include "iron_goat/deser.h"
#include "distract/util.h"

bool load_map_from_file(game_t *game, ig_map_t *map_conf)
{
    json_t conf = {0};

    if (json_parser(&conf, game->scene->world_file) == false) {
        print_error("Could not init map loader");
        return (false);
    }
    if (init_iron_goat_map(&conf, map_conf) == false) {
        destroy_json(&conf);
        print_error("Could not init map loader");
        return (false);
    }
    destroy_json(&conf);
    return (true);
}

static bool generate_entities_layer(game_t *game UNUSED,
    layer_manager_t *manager)
{
    entity_t *entity_stock = NULL;

    if ((entity_stock = create_entity(game, TILESET_LAYER_MANAGER)) == NULL)
        return (false);
    manager->tilesets = entity_stock->instance;
    for (usize_t i = 0; i < manager->tilesets->tileset->size; i++) {
        if (create_entity(game, TILESET_LAYER) == NULL)
            return (false);
    }
    if ((entity_stock = create_entity(game, COLLISION_LAYER)) == NULL)
        return (false);
    manager->collision = entity_stock->instance;
    if ((entity_stock = create_entity(game, OBJECT_LAYER_MANAGER)) == NULL)
        return (false);
    return (true);
}

bool create_map_loader(game_t *game UNUSED, entity_t *entity)
{
    map_loader_t *map_loader = dcalloc(sizeof(map_loader_t), 1);
    layer_manager_t manager = {0};
    ig_map_t map = {0};

    D_ASSERT(map_loader, NULL, "", false)
    D_ASSERT(generate_entities_layer(game, &manager), false,
        "Could not generate layers", false);
    D_ASSERT(load_map_from_file(game, &map), false,
        "Could not read mapfile", false);
    manager.mapsize = (sfVector2u){map.width, map.height};
    manager.tilesize = map.tilewidth;
    map_loader->manager = manager;
    map_loader->entity = entity;
    entity->instance = map_loader;
    return (true);
}

void destroy_map_loader(game_t *game UNUSED, entity_t *entity)
{
    map_loader_t *map_loader = entity->instance;

    free(map_loader);
}