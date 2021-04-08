/*
** EPITECH PROJECT, 2021
** load
** File description:
** texture
*/

#include "myrpg/map/map.h"
#include "distract/debug.h"
#include "distract/resources.h"

static bool check_tileset_overlapping(ig_tileset_t *tileset,
    struct tileset_parser_args *args)
{
    for (usize_t i = 0; i < args->layer->data.size; i++) {
        if (args->layer->data.data[i] == 0)
            continue;
        D_ASSERT(MATCH_TILESET(args->layer->data.data[i], *tileset), false,
            "Tileset might be ovelapping", false);
    }
    return (true);
}

static bool check_tileset_logic(game_t *game,
    struct tileset_parser_args *args, i64_t random_id,
    usize_t *tilesetloaded)
{
    usize_t i = 0;
    ig_tileset_t tilesetinfo;

    for (; i < args->tileset->size; i++) {
        tilesetinfo = args->tileset->data[i];
        if (MATCH_TILESET(random_id, tilesetinfo))
            return;
    }
    D_ASSERT(i, args->tileset->size,
        "One id has no tileset attributed", false);
    if (check_tileset_overlapping(&tilesetinfo, args) == false)
        return (false);
    if ((args->manager->texture =
        create_texture(game, args->tileset->data[i].image, NULL)) == NULL)
        return (false);
    *tilesetloaded = i;
    return (true);
}

bool load_tileset_texture(game_t *game, struct tileset_parser_args *args,
    usize_t *tilesetloaded)
{
    u64_t random_id = 0;

    for (; *tilesetloaded < args->layer->data.size; (*tilesetloaded)++) {
        if (args->layer->data.data[*tilesetloaded] != 0) {
            random_id = args->layer->data.data[*tilesetloaded];
            break;
        }
    if (random_id == 0) {
        ASSERT_PRINTF("Layer N°%ld is empty", (*tilesetloaded));
        return (false);
    }
    return (check_tileset_logic(game, args,
        get_real_tile_id_and_rotation(random_id).id, tilesetloaded);
}