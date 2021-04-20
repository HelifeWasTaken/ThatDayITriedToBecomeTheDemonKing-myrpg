/*
** EPITECH PROJECT, 2021
** object
** File description:
** obj
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_object(struct iron_goat_object *self)
{
    FREE(self->name);
    if (self->properties)
        self->properties->clear(&self->properties);
    FREE(self->template);
    FREE(self->type);
    if (self->polygon)
        self->polygon->clear(&self->polygon);
}

static bool iron_goat_object_load_props(struct json *conf,
    struct iron_goat_object *self)
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

static bool iron_goat_object_load_polygon(struct json *conf,
    struct iron_goat_object *self)
{
    struct json_array *data = conf->v.array;
    struct iron_goat_point point = {0};

    if ((self->polygon = VECTOR_CREATE(ig_point)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        point = (struct iron_goat_point){0};
        if (init_iron_goat_point(&data->data[i], &point) == false)
            return (false);
        if (self->polygon->push_back(&self->polygon, point) == -1)
            return (false);
    }
    return (true);
}

static const struct json_deser_data IG_OBJECT[] = {
    {
        .data = ".ellipse",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_object, ellipse),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = true
    },
    {
        .data = ".gid",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_object, gid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = true
    },
    {
        .data = ".height",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, height),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".id",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_object, id),
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
        .offset = offsetof(struct iron_goat_object, name),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".point",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_object, point),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = true
    },
    {
        .data = ".polygon",
        .size_data = sizeof(VECTOR(ig_point) *),
        .offset = offsetof(struct iron_goat_object, polygon),
        .intern = {
            .callback = iron_goat_object_load_polygon,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = true
    },
    {
        .data = ".properties",
        .size_data = sizeof(VECTOR(ig_prop) *),
        .offset = offsetof(struct iron_goat_object, properties),
        .intern = {
            .callback = iron_goat_object_load_props,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
    {
        .data = ".rotation",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, rotation),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".template",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_object, template),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = true
    },
    {
        .data = ".type",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_object, type),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".visible",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_object, visible),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    },
    {
        .data = ".width",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, width),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".x",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, x),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".y",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_object, y),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    }
};

bool init_iron_goat_object(struct json *conf,
    struct iron_goat_object *self)
{
    DESER_LOOP(conf, self, IG_OBJECT);
}