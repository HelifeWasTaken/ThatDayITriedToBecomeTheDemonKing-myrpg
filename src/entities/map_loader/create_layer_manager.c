/*
** EPITECH PROJECT, 2020
** layer
** File description:
** Entity
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
#include "myrpg/define.h"
#include "iron_goat/deser.h"
#include "myrpg/map.h"
#include "distract/debug.h"
#include "myrpg/mapdata.h"

static const char *MAP_DIRECTORY = "asset/map_asset/map_files/";

bool create_layer_manager(game_t *game UNUSED, entity_t *entity)
{
    layer_manager_t *layer = ecalloc(sizeof(layer_manager_t), 1);
    json_t conf = {0};
    ig_map_t map = {0};
    vertex_map_t vmap = {0};
    entity_t *warpsentity = create_entity(game, WARP);

    D_ASSERT(layer, NULL, "Layer could not be created", false);
    D_ASSERT(warpsentity, NULL, "Warps could not be created", false);
    layer->warp_list = warpsentity->instance;
    D_ASSERT(json_parser(&conf,
        MAP_FILES[game->scene->world_id].m_files.mapfile), false, "", false);
    D_ASSERT(init_iron_goat_map(&conf, &map), false, "", false);
    destroy_json(&conf);
    if (load_vertex_array_map(game, &map, &vmap, MAP_DIRECTORY) == false)
        return (false);
    destroy_iron_goat_map(&map);
    layer->entity = entity;
    layer->map = vmap;
    entity->instance = layer;
    return (true);
}

void destroy_layer_manager(game_t *game UNUSED, entity_t *entity)
{
    layer_manager_t *layer = entity->instance;

    if (layer->map.v_texture.tileset)
        free(layer->map.v_texture.tileset);
    if (layer->map.v_vertex.vec) {
        for (usize_t i = 0; i < layer->map.v_vertex.size; i++) {
            SAFE_RESOURCE_DESTROY(sfVertexArray_destroy,
                    layer->map.v_vertex.vec[i].vertex);
        }
        free(layer->map.v_vertex.vec);
    }
    if (layer->map.v_collision.layer != NULL)
        free(layer->map.v_collision.layer);
    free(layer);
}
