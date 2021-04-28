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
#include "myrpg/state.h"

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

static bool load_reference_layer(game_t *game UNUSED, layer_manager_t *manager)
{
    game_state_t *state = game->state;
    bool ret = load_property_uint(state->map.properties, &manager->z, "z",
        "Could not load z property for npc and player in map_loader.c");

    if (ret)
        state->z = manager->z;
    return (ret);
}

static bool generate_entities_layer(game_t *game UNUSED,
        layer_manager_t *manager)
{
    entity_t *entity_stock = NULL;

    if (load_reference_layer(game, manager) == false)
        return (false);
    if ((entity_stock = create_entity(game, TILESET_LAYER_MANAGER)) == NULL)
        return (false);
    manager->tilesets = entity_stock->instance;
    for (usize_t i = 0; i < manager->tilesets->tileset->size; i++) {
        printf("entity count: %ld\n", i);
        fflush(stdout);
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
    game_state_t *state = game->state;
    ig_map_t map = state->map;

    D_ASSERT(map_loader, NULL, "", false);
    D_ASSERT(generate_entities_layer(game, &manager), false,
        "Could not generate layers", false);
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
