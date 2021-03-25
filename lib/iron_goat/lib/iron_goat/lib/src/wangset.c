/*
** EPITECH PROJECT, 2021
** wangset
** File description:
** wang
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_wangset(struct iron_goat_wangset *self)
{
    if (self->cornercolors)
        self->cornercolors->clear(&self->cornercolors);
    if (self->edgecolors)
        self->edgecolors->clear(&self->edgecolors);
    if (self->properties)
        self->properties->clear(&self->properties);
    if (self->wangtiles)
        self->wangtiles->clear(&self->wangtiles);
    FREE(self->name);
}

bool load_iron_goat_wangset_cornercolors(struct json *conf,
    struct iron_goat_wangset *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_wangcolor color = {0};

    if ((self->cornercolors = VECTOR_CREATE(ig_wangcolor)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        color = (struct iron_goat_wangcolor){0};
        if (init_iron_goat_wangcolor(&data->data[i], &color) == false)
            return (false);
        if (self->cornercolors->push_back(&self->cornercolors, color) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_wangset_edgecolors(struct json *conf,
    struct iron_goat_wangset *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_wangcolor color = {0};

    if ((self->edgecolors = VECTOR_CREATE(ig_wangcolor)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        color = (struct iron_goat_wangcolor){0};
        if (init_iron_goat_wangcolor(&data->data[i], &color) == false)
            return (false);
        if (self->edgecolors->push_back(&self->edgecolors, color) == -1)
            return (false);
    }
    return (true);
}

bool load_iron_goat_wangset_properties(struct json *conf,
    struct iron_goat_wangset *self)
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

bool load_iron_goat_wangset_wangtiles(struct json *conf,
    struct iron_goat_wangset *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_wangtile wangtile = {0};

    if ((self->wangtiles = VECTOR_CREATE(ig_wangtile)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        wangtile = (struct iron_goat_wangtile){0};
        if (init_iron_goat_wangtile(&data->data[i], &wangtile) == false)
            return (false);
        if (self->wangtiles->push_back(&self->wangtiles, wangtile) == -1)
            return (false);
    }
    return (true);
}

static const struct json_deser_data IG_WANGSET[] = {
    {
        .data = ".cornercolors",
        .size_data = sizeof(VECTOR(ig_wangcolor) *),
        .offset = offsetof(struct iron_goat_wangset, cornercolors),
        .intern = {
            .callback = load_iron_goat_wangset_cornercolors,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".edgecolors",
        .size_data = sizeof(VECTOR(ig_wangcolor) *),
        .offset = offsetof(struct iron_goat_wangset, edgecolors),
        .intern = {
            .callback = load_iron_goat_wangset_edgecolors,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_wangset, name),
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
        .offset = offsetof(struct iron_goat_wangset, properties),
        .intern = {
            .callback = load_iron_goat_wangset_properties,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".tile",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_wangset, tile),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".wangtiles",
        .size_data = sizeof(VECTOR(ig_wangtile) *),
        .offset = offsetof(struct iron_goat_wangset, wangtiles),
        .intern = {
            .callback = load_iron_goat_wangset_wangtiles,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    }
};

bool init_iron_goat_wangset(struct json *conf, struct iron_goat_wangset *self)
{
    DESER_LOOP(conf, self, IG_WANGSET);
}