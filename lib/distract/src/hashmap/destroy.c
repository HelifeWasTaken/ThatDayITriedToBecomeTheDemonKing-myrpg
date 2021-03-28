/*
** EPITECH PROJECT, 2021
** distract
** File description:
** hashmap
*/

#include "stdlib.h"
#include "distract/hashmap.h"

void hashmap_destroy(hashmap_t *map)
{
    if (map) {
        if (map->values)
            free(map->values);
        if (map->keys)
            free(map->keys);
        free(map);
    }
}