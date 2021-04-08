/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** warpzone
*/

#include "myrpg/map/object.h"

void destroy_layer_object_warpzone(layer_object_value_t *object)
{
    if (object->warp->file)
        free(object->warp->file);
}
