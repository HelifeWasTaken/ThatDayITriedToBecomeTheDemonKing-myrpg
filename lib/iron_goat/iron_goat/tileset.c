/*
** EPITECH PROJECT, 2021
** tileset
** File description:
** tilese
*/

#include <iron_goat/deser.h>
#include "priv/tileset/tileset.h"

void destroy_iron_goat_tileset(struct iron_goat_tileset *self)
{
    FREE(self->image);
    FREE(self->name);
    if (self->properties)
        self->properties->clear(&self->properties);
    FREE(self->source);
    if (self->terrains)
        self->terrains->clear(&self->terrains);
    if (self->tiles)
        self->tiles->clear(&self->tiles);
    FREE(self->type);
    if (self->wangsets)
        self->wangsets->clear(&self->wangsets);
}

static bool load_iron_goat_tileset_terrains(struct json *conf,
    struct iron_goat_tileset *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_terrain terrain = {0};

    if ((self->terrains = VECTOR_CREATE(ig_terrain)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        terrain = (struct iron_goat_terrain){0};
        if (init_iron_goat_terrain(&data->data[i], &terrain) == false)
            return (false);
        if (self->terrains->push_back(&self->terrains, terrain) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_tileset_tiles(struct json *conf,
    struct iron_goat_tileset *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_tile tile = {0};

    if ((self->tiles = VECTOR_CREATE(ig_tile)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        tile = (struct iron_goat_tile){0};
        if (init_iron_goat_tile(&data->data[i], &tile) == false)
            return (false);
        if (self->tiles->push_back(&self->tiles, tile) == -1)
            return (false);
    }
    return (true);
}

static bool load_iron_goat_tileset_wangset(struct json *conf,
    struct iron_goat_tileset *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_wangset wangset = {0};

    if ((self->wangsets = VECTOR_CREATE(ig_wangset)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        wangset = (struct iron_goat_wangset){0};
        if (init_iron_goat_wangset(&data->data[i], &wangset) == false)
            return (false);
        if (self->wangsets->push_back(&self->wangsets, wangset) == -1)
            return (false);
    }
    return (true);
}

static const struct json_deser_data IG_TILESET[] = {
    {
        .data = ".backgroundcolor",
        .size_data = sizeof(u32_t),
        .offset = offsetof(struct iron_goat_tileset, backgroundcolor),
        .intern = {
            .callback = iron_goat_get_color,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".columns",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, columns),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".firstgid",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, firstgid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".grid",
        .size_data = sizeof(OPT(ig_grid)),
        .offset = offsetof(struct iron_goat_tileset, grid),
        .intern = {
            .callback = load_iron_goat_tileset_grid,
            .woff = false
        },
        .type = JSON_ANY,
        .opt = true
    },
    {
        .data = ".image",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_tileset, image),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".imageheight",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, imageheight),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".imagewidth",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, imagewidth),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".margin",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, margin),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_tileset, name),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".properties",
        .size_data = sizeof(VECTOR(ig_prop) *),
        .offset = offsetof(struct iron_goat_tileset, properties),
        .intern = {
            .callback = load_iron_goat_tileset_properties,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".source",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_tileset, source),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".spacing",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, spacing),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".terrains",
        .size_data = sizeof(VECTOR(ig_terrain)),
        .offset = offsetof(struct iron_goat_tileset, terrains),
        .intern = {
            .callback = load_iron_goat_tileset_terrains,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".tilecount",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, tilecount),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".tiledversion",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_tileset, tiledversion),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".tileheight",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, tileheight),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".tileoffset",
        .size_data = sizeof(ig_tileoffset_t),
        .offset = offsetof(struct iron_goat_tileset, tileoffset),
        .intern = {
            .callback = load_iron_goat_tileset_tileoffset,
            .woff = false
        },
        .type = JSON_ANY,
        .opt = true
    },
    {
        .data = ".tiles",
        .size_data = sizeof(VECTOR(ig_tile) *),
        .offset = offsetof(struct iron_goat_tileset, tiles),
        .intern = {
            .callback = load_iron_goat_tileset_tiles,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".tilewidth",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tileset, tilewidth),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".transparentcolor",
        .size_data = sizeof(OPT(u32)),
        .offset = offsetof(struct iron_goat_tileset, transparentcolor),
        .intern = {
            .callback = load_iron_goat_tileset_transparent_color,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".type",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_tileset, type),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".wangsets",
        .size_data = sizeof(VECTOR(ig_wangset) *),
        .offset = offsetof(struct iron_goat_tileset, wangsets),
        .intern = {
            .callback = load_iron_goat_tileset_wangset,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    }
};

bool init_iron_goat_tileset(struct json *conf, struct iron_goat_tileset *self)
{
    DESER_LOOP(conf, self, IG_TILESET);
}