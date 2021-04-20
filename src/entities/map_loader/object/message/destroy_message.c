/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** message
*/

#include "myrpg/map/object.h"
#include "stdlib.h"

void destroy_layer_object_message(layer_object_value_t *object)
{
    if (object->pnj.message != NULL) {
        for (usize_t i = 0; object->pnj.message[i]; i++)
            free(object->pnj.message[i]);
        free(object->pnj.message);
    }
    if (object->pnj.name != NULL)
        free(object->pnj.name);
}