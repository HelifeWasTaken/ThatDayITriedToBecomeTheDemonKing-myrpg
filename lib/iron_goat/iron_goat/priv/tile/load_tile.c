/*
** EPITECH PROJECT, 2021
** iron_goat
** File description:
** load_tile.c
*/

#include <iron_goat/deser.h>
#include "tile.h"

bool load_iron_goat_tile_animation(struct json *conf,
        struct iron_goat_tile *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_frame anim = {0};

    if ((self->animation = VECTOR_CREATE(ig_frame)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        anim = (struct iron_goat_frame){0};
        if (init_iron_goat_frame(&data->data[i], &anim) == false)
            return (false);
        if (self->animation->push_back(&self->animation, anim) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_tile_objectgroup(struct json *conf,
        struct iron_goat_tile *self)
{
    self->objectgroup.is_ok = true;
    return (init_iron_goat_layer(conf, &self->objectgroup.value));
}

bool load_iron_goat_tile_properties(struct json *conf,
        struct iron_goat_tile *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_property prop = {0};

    if ((self->properties = VECTOR_CREATE(ig_prop)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        prop = (struct iron_goat_property){0};
        if (init_iron_goat_props(&data->data[i], &prop) == false)
            return (false);
        if (self->properties->push_back(&self->properties, prop) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_tile_terrain(struct json *conf,
        struct iron_goat_tile *self)
{
    self->terrain.is_ok = true;
    return (init_iron_goat_tile_terrain(conf, &self->terrain.value));
}

bool load_iron_goat_tile_probabilities(struct json *conf,
        struct iron_goat_tile *self)
{
    self->probability.is_ok = true;
    self->probability.value = conf->v.number;
    return (true);
}
