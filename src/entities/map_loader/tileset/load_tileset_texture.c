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
    u64_t real_id = 0;

    for (usize_t i = 0; i < args->layer->data.size; i++) {
        if (args->layer->data.data[i] == 0)
            continue;
        real_id = get_real_tile_id_and_rotation(args->layer->data.data[i]).id;
        if (!(real_id >= tileset->firstgid &&
            real_id <= tileset->firstgid + tileset->tilecount)) {
            print_error("Tileset might be overlapping");
            return (false);
        }
    }
    return (true);
}

static bool create_texture_tileset(game_t *game,
    struct tileset_parser_args *args, usize_t i)
{
    char *file = eformat("%s%s",
        "asset/map_asset/map_files/", args->tileset->data[i].image);

    D_ASSERT(file, NULL, "Could not allocate memory", false);
    args->manager->texture =
        create_texture(game, file, NULL);
    FREE(file);
    return (args->manager->texture != NULL);
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
            break;
    }
    D_ASSERT(i, args->tileset->size,
        "One id has no tileset attributed", false);
    if (check_tileset_overlapping(&tilesetinfo, args) == false)
        return (false);
    if (create_texture_tileset(game, args, i) == false)
        return (false);
    *tilesetloaded = i;
    return (true);
}

bool load_tileset_texture(game_t *game, struct tileset_parser_args *args,
    usize_t *tilesetloaded)
{
    u64_t random_id = 0;

    for (; *tilesetloaded < args->layer->data.size; (*tilesetloaded)++)
        if (args->layer->data.data[*tilesetloaded] != 0) {
            random_id = args->layer->data.data[*tilesetloaded];
            break;
        }
    if (random_id == 0) {
        DEBUG_PRINTF("Layer N°%ld is empty", (*tilesetloaded));
        return (false);
    }
    return (check_tileset_logic(game, args,
        get_real_tile_id_and_rotation(random_id).id, tilesetloaded));
}