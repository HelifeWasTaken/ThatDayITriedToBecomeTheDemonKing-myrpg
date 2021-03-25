/*
** EPITECH PROJECT, 2021
** distract
** File description:
** set
*/

#include "stdlib.h"
#include "distract/hashmap.h"

void hashmap_set(hashmap_t **map_ptr, void *key, void *value)
{
    hashmap_t *map = *map_ptr;
    size_t index = hashmap_getindex(map, key);

    map->keys[index] = key;
    if(map->values[index] == NULL)
        map->size++;
    map->values[index] = value;
    if(map->size * 4 >= map->capacity * 3)
        hashmap_resize(map_ptr);
}