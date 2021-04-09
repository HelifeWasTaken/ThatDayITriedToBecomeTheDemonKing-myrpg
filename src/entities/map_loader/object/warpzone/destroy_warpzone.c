/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** warpzone
*/

#include "myrpg/map/object.h"
#include "stdlib.h"

void destroy_layer_object_warpzone(layer_object_value_t *object)
{
    if (object->warp.world)
        free(object->warp.world);
}
