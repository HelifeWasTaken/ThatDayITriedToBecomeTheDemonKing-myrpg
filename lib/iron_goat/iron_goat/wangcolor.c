/*
** EPITECH PROJECT, 2021
** wangcolor
** File description:
** color
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_wangcolor(struct iron_goat_wangcolor *self)
{
    FREE(self->name);
}

bool load_iron_goat_wangcolor_properties(struct json *conf,
        struct iron_goat_wangcolor *self)
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

static const struct json_deser_data IG_WANGCOLOR[] = {
    {
        .data = ".color",
        .size_data = sizeof(u32_t),
        .offset = offsetof(struct iron_goat_wangcolor, color),
        .intern = {
            .callback = iron_goat_get_color,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_wangcolor, name),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".probability",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_wangcolor, probability),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".properties",
        .size_data = sizeof(VECTOR(ig_prop) *),
        .offset = offsetof(struct iron_goat_wangcolor, properties),
        .intern = {
            .callback = load_iron_goat_wangcolor_properties,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".tile",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_wangcolor, tile),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    }
};

bool init_iron_goat_wangcolor(struct json *conf,
        struct iron_goat_wangcolor *self)
{
    DESER_LOOP(conf, self, IG_WANGCOLOR);
}
