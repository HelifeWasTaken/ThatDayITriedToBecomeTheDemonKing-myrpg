/*
** EPITECH PROJECT, 2021
** load
** File description:
** wangset
*/

#include "wangset.h"

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
