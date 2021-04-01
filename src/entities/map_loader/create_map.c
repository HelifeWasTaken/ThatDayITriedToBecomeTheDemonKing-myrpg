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

static char *FILE_MAP[] = {
    #include "maps_files.h.in"
};

bool create_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = ecalloc(sizeof(layer_t), 1);
    json_t conf = {0};
    ig_map_t map = {0};
    vertex_map_t vmap = {0};

    if (layer == NULL)
        return (false);
    if (json_parser(&conf, FILE_MAP[game->scene->id]) == false)
        return (false);
    if (init_iron_goat_map(&conf, &map) == false)
        return (false);
    destroy_json(&conf);
    if (load_vertex_array_map(game, &map, &vmap,
        "asset/map_asset/") == false)
        return (false);
    destroy_iron_goat_map(&map);
    layer->entity = entity;
    layer->map = vmap;
    entity->instance = layer;
    return (true);
}

void destroy_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = entity->instance;

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

void draw_layer(game_t *game UNUSED, entity_t *entity)
{
    layer_t *layer = entity->instance;

    draw_all_vertex_map(game->window, &layer->map);
}
