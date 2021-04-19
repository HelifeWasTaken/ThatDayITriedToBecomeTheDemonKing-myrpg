/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** objects
*/

#include "myrpg/map/map.h"

void (*DESTROY_PTR[])(layer_object_value_t *) = {
    destroy_layer_object_warpzone,
    destroy_layer_object_message
};

void destroy_layer_object_data(struct layer_object_data *layer)
{
    DESTROY_PTR[layer->type](&layer->object);
}
