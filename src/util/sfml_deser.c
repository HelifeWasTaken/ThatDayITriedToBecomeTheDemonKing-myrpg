/*
** EPITECH PROJECT, 2021
** sfml
** File description:
** deser
*/

#include "iron_goat/deser.h"
#include "erty/json.h"
#include <SFML/Graphics.h>

static const struct json_deser_data DESER_V2I[] = {
    {
        .data = ".x",
        .size_data = sizeof(int),
        .offset = offsetof(sfVector2i, x),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".y",
        .size_data = sizeof(int),
        .offset = offsetof(sfVector2i, y),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
};

bool deser_vector2i(struct json *conf, size_t offset, void *data)
{
    char *dataptr = (char *)data;
    sfVector2i *value = (sfVector2i *)(dataptr + offset);

    DESER_LOOP(conf, &value[0], DESER_V2I);
}

bool deser_vector2f(struct json *conf, size_t offset, void *data)
{
    char *dataptr = (char *)data;
    sfVector2f *value = (sfVector2f *)(dataptr + offset);
    sfVector2i container = {0};

    if (deser_vector2i(conf, 0, &container) == false)
        return (false);
    value->x = container.x;
    value->y = container.y;
    return (true);
}



static const struct json_deser_data DESER_RI[] = {
    {
        .data = ".top",
        .size_data = sizeof(int),
        .offset = offsetof(sfIntRect, top),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".left",
        .size_data = sizeof(int),
        .offset = offsetof(sfIntRect, left),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".width",
        .size_data = sizeof(int),
        .offset = offsetof(sfIntRect, width),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".height",
        .size_data = sizeof(int),
        .offset = offsetof(sfIntRect, height),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    }
};

bool deser_irect(struct json *conf, size_t offset, void *data)
{
    char *dataptr = (char *)data;
    sfIntRect *value = (sfIntRect *)(dataptr + offset);

    DESER_LOOP(conf, &value[0], DESER_RI);
}

bool deser_frect(struct json *conf, size_t offset, void *data)
{
    char *dataptr = (char *)data;
    sfFloatRect *value = (sfFloatRect *)(dataptr + offset);
    sfIntRect container = {0};

    if (deser_vector2i(conf, 0, &container) == false)
        return (false);
    value->top = container.top;
    value->left = container.left;
    value->height = container.height;
    value->width = container.width;
    return (true);
}