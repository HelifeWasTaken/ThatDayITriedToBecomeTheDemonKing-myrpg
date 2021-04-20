/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** objects
*/

#include "myrpg/map/map.h"

struct destroy_ptr_fun {
    void (*ptr)(layer_object_value_t *);
};

static const struct destroy_ptr_fun OBJ_DESTROY[] = {
    { destroy_layer_object_warpzone },
    { destroy_layer_object_message }
};

void destroy_layer_object_data(layer_object_info_t *obj)
{
    OBJ_DESTROY[obj->obj.type].ptr(&obj->obj.object);
}