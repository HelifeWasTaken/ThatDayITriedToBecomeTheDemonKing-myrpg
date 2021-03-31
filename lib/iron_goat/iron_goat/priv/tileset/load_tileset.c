/*
** EPITECH PROJECT, 2021
** load
** File description:
** tileset
*/

#include "tileset.h"

bool load_iron_goat_tileset_grid(struct json *conf,
    struct iron_goat_tileset *self)
{
    self->grid.is_ok = true;
    return (init_iron_goat_grid(conf, &self->grid.value));
}

bool load_iron_goat_tileset_tileoffset(struct json *conf,
    struct iron_goat_tileset *self)
{
    return (init_iron_goat_tileoffset(conf, &self->tileoffset));
}

bool load_iron_goat_tileset_transparent_color(struct json *conf,
    struct iron_goat_tileset *self)
{
    self->transparentcolor.is_ok = true;
    return (hextoint(conf->v.string, &self->transparentcolor.value));
}

bool load_iron_goat_tileset_properties(struct json *conf,
    struct iron_goat_tileset *self)
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
