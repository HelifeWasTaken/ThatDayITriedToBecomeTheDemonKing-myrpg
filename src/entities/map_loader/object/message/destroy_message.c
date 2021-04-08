/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** message
*/

#include "myrpg/map/object.h"

void destroy_layer_object_message(layer_object_value_t *object)
{
    if (object->message == NULL)
        return;
    for (usize_t i = 0; i < object->message[i]; i++)
        free(object->message[i]);
    free(object->message);
}