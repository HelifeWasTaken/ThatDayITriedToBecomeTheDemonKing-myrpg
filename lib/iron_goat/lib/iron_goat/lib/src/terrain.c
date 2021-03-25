/*
** EPITECH PROJECT, 2021
** terrain
** File description:
** terrain
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_terrain(struct iron_goat_terrain *self)
{
    FREE(self->name);
    if (self->properties)
        self->properties->clear(&self->properties);
}

static bool load_iron_goat_prop_terrain_vector(struct json *conf,
                                        struct iron_goat_terrain *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_property prop = {0};

    if ((self->properties = VECTOR_CREATE(ig_prop)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        prop = (struct iron_goat_property){0};
        init_iron_goat_props(&data->data[i], &prop);
        if (self->properties->push_back(&self->properties, prop) == -1)
            return (false);
    }
    return (true);
}

static const struct json_deser_data IG_TERRAIN[] = {
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_terrain, name),
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
        .offset = offsetof(struct iron_goat_terrain, properties),
        .intern = {
            .callback = load_iron_goat_prop_terrain_vector,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".tile",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_terrain, tile),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
};

bool init_iron_goat_terrain(struct json *conf, struct iron_goat_terrain *self)
{
    DESER_LOOP(conf, self, IG_TERRAIN);
}