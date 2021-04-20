/*
** EPITECH PROJECT, 2021
** load_tilesets
** File description:
** load
*/

#include "myrpg/map/map.h"
#include "distract/debug.h"
#include "distract/resources.h"

int load_tileset_info(game_t *game,
    layer_tileset_info_t *tileset_info, usize_t i, ig_map_t *map)
{
    usize_t tilesetchosen = 0;

    D_ASSERT(map->layers->data[i].data.data, NULL,
        "Layer was a tilelayer but data field is NULL", 2);
    if (estrcmp(map->layers->data[i].name, "collision") == 0)
        return (1);
    if (load_tileset_texture(game, &(struct tileset_parser_args){
        &map->layers->data[i], tileset_info, map->tilesets},
        &tilesetchosen) == false)
        return (2);
    tileset_info->z = i;
    tileset_info->vtx = create_vertex(game, map->layers->data[i].name);
    if (load_vertex_tileset(tileset_info, tilesetchosen, i, map) == false)
        return (2);
    return (0);
}

bool load_tileset(game_t *game, ig_map_t *map, tileset_manager_t *manager)
{
    layer_tileset_info_t tileset_info = {0};
    int returncode = 0;

    if ((manager->tileset = VECTOR_CREATE(ltile_info)) == NULL)
        return (false);
    for (usize_t i = 0; i < map->layers->size; i++) {
        tileset_info = (layer_tileset_info_t){0};
        if (map->layers->data[i].type != LAYER_TILELAYER)
            continue;
        if ((returncode = load_tileset_info(game, &tileset_info, i, map)) == 2)
            return (false);
        if (returncode == 1)
            continue;
        if (manager->tileset->push_back(&manager->tileset, tileset_info) == -1)
            return (false);
    }
    D_ASSERT(manager->tileset->size, 0, "Warn: Did not load any tileset", true);
    return (true);
}