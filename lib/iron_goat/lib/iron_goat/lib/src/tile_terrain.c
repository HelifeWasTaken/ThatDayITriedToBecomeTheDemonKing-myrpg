/*
** EPITECH PROJECT, 2021
** tile
** File description:
** terrain
*/

#include <iron_goat/deser.h>

static bool get_iron_goat_tile_terrain(struct json *conf,
    struct iron_goat_tile_terrain *self)
{
    struct json_array *data = conf->v.array;

    if (data->size != 4) {
        ASSERT("Json", "Tile terrain: array is of invalid size");
        return (false);
    }
    for (size_t i = 0; i < data->size; i++)
        self->tile[i] = data->data[i].v.number;
    return (true);
}

static const struct json_deser_data IG_TILE_TERRAIN[] = {
    {
        .data = ".tile",
        .size_data = sizeof(size_t) * 4,
        .offset = offsetof(struct iron_goat_tile_terrain, tile),
        .intern = {
            .callback = get_iron_goat_tile_terrain,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    }
};

bool init_iron_goat_tile_terrain(struct json *conf,
                                struct iron_goat_tile_terrain *self)
{
    DESER_LOOP(conf, self, IG_TILE_TERRAIN);
}