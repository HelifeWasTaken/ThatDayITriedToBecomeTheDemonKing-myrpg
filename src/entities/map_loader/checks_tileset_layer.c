/*
** EPITECH PROJECT, 2021
** checks
** File description:
** tilesets
*/

#include "myrpg/map.h"

static bool load_vertex_array_map_get_tileset_process(ig_map_t *map,
        usize_t v_check, usize_t *tileset)
{
    for (usize_t i = 0; i < map->tilesets->size; i++) {
        if (map->tilesets->data[i].firstgid <= v_check &&
                v_check < map->tilesets->data[i].firstgid +
                map->tilesets->data[i].tilecount) {
            *tileset = i;
            break;
        }
    }
    if (*tileset == map->tilesets->size) {
        ASSERT("Vertex array", "Tileset not found");
        return (false);
    }
    return (true);
}

bool load_vertex_array_map_get_tileset(ig_map_t *map,
        struct iron_goat_layer *layer, usize_t *tileset)
{
    int64_t v = 0;

    for (usize_t i = 0; 1; i++) {
        if (layer->data->data[i] != 0) {
            v = get_real_tile_id_and_rotation(layer->data->data[i]).id;
            break;
        }
        if (layer->data->size == i) {
            ASSERT("Vertex array", "One layer is empty");
            return (false);
        }
    }
    return (load_vertex_array_map_get_tileset_process(map, v, tileset));
}

bool check_tileset_and_data(struct iron_goat_layer *layer,
        struct iron_goat_tileset *tileset)
{
    u64_t value = 0;

    for (usize_t i = 0; i < layer->data->size; i++) {
        value = get_real_tile_id_and_rotation(layer->data->data[i]).id;
        if (value == 0)
            continue;
        if (!(tileset->firstgid <= value &&
                    value <= tileset->firstgid +
                    tileset->tilecount)) {
            ASSERT("Vertex array", "Two layer might certainly be merged");
            return (false);
        }
    }
    return (true);
}
