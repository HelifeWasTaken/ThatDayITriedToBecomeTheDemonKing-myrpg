/*
** EPITECH PROJECT, 2021
** tile
** File description:
** tile
*/

#include <iron_goat/deser.h>
#include "priv/tile/tile.h"

void destroy_iron_goat_tile(struct iron_goat_tile *self)
{
    if (self->animation)
        self->animation->clear(&self->animation);
    FREE(self->image);
    if (self->properties)
        self->properties->clear(&self->properties);
    FREE(self->type);
}

static const struct json_deser_data IG_TILE[] = {
    {
        .data = ".animation",
        .size_data = sizeof(VECTOR(ig_frame) *),
        .offset = offsetof(struct iron_goat_tile, animation),
        .intern = {
            .callback = load_iron_goat_tile_animation,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".id",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_tile, id),
        .intern = {
            .callback = NULL,
            .woff = true
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".image",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_tile, image),
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
        .offset = offsetof(struct iron_goat_tile, imageheight),
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
        .offset = offsetof(struct iron_goat_tile, imagewidth),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".objectgroup",
        .size_data = sizeof(OPT(ig_layer)),
        .offset = offsetof(struct iron_goat_tile, objectgroup),
        .intern = {
            .callback = load_iron_goat_tile_objectgroup,
            .woff = false
        },
        .type = JSON_ANY,
        .opt = true
    },
    {
        .data = ".probabilty",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_tile, probability),
        .intern = {
            .callback = load_iron_goat_tile_probabilities,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".properties",
        .size_data = sizeof(VECTOR(ig_prop) *),
        .offset = offsetof(struct iron_goat_tile, properties),
        .intern = {
            .callback = load_iron_goat_tile_properties,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".terrain",
        .size_data = sizeof(OPT(ig_tile_terrain)),
        .offset = offsetof(struct iron_goat_tile, terrain),
        .intern = {
            .callback = load_iron_goat_tile_terrain,
            .woff = false
        },
        .type =  JSON_ARR,
        .opt = true
    },
    {
        .data = ".type",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_tile, type),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
};

bool init_iron_goat_tile(struct json *conf, struct iron_goat_tile *self)
{
    DESER_LOOP(conf, self, IG_TILE);
}
