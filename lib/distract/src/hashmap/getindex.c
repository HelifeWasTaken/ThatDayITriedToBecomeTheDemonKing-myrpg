/*
** EPITECH PROJECT, 2021
** distract
** File description:
** index
*/

#include "stdlib.h"
#include "distract/hashmap.h"

size_t hashmap_getindex(hashmap_t *map, void *key)
{
    size_t index = map->hasher(map, key);

    while (map->keys[index] != NULL && map->keys[index] != key) {
        index = (index + 1) % map->capacity;
    }
    return (index);
}