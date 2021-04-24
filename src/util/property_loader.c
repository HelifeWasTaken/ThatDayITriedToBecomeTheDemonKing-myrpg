/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** property_loader.c
*/

#include "myrpg/map/map.h"
#include "myrpg/util.h"
#include "distract/debug.h"

bool load_property_int(VECTOR(ig_prop) *prop, int64_t *value,
                        char *search, char *error)
{
    D_ASSERT(prop, NULL, error, false);
    for (usize_t i = 0; i < prop->size; i++) {
        if (prop->data[i].type == PROP_INT &&
            estrcmp(prop->data[i].name,search) == 0) {
            *value = prop->data[i].value.i;
            return (true);
        }
    }
    print_error(error);
    return (false);
}

bool load_property_string(VECTOR(ig_prop) *prop, char **buffer,
    char *search, char *error)
{
    D_ASSERT(prop, NULL, error, false);
    for (usize_t i = 0; i < prop->size; i++) {
        if (prop->data[i].type == PROP_STRING &&
            estrcmp(prop->data[i].name, search) == 0) {
            *buffer = prop->data[i].value.str;
            return (true);
        }
    }
    print_error(error);
    return (false);
}

bool load_property_uint(VECTOR(ig_prop) *prop, usize_t *value,
                        char *search, char *error)
{
    D_ASSERT(prop, NULL, error, false);
    for (usize_t i = 0; i < prop->size; i++) {
        if (prop->data[i].type == PROP_INT &&
            estrcmp(prop->data[i].name, search) == 0) {
            *value = prop->data[i].value.i;
            return (true);
        }
    }
    print_error(error);
    return (false);
}