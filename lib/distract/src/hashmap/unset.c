/*
** EPITECH PROJECT, 2021
** distract
** File description:
** unset
*/

#include "stdlib.h"
#include "distract/hashmap.h"

void hashmap_unset(hashmap_t **map_ptr, void *key)
{
    hashmap_t *map = *map_ptr;
    size_t index = hashmap_getindex(map, key);

    if (map->values[index] != NULL)
        map->size--;
    map->keys[index] = NULL;
    map->values[index] = NULL;
}
