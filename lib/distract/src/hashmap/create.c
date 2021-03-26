/*
** EPITECH PROJECT, 2021
** distract
** File description:
** create
*/

#include "stdlib.h"
#include <distract/hashmap.h>
#include <distract/util.h>

static size_t no_hashing_fnc(hashmap_t *map, void *key)
{
    return (((size_t) key) % map->capacity);
}

hashmap_t *hashmap_create(size_t capacity,
    size_t (*hasher)(hashmap_t *map, void *key))
{
    hashmap_t *map = dcalloc(1, sizeof(hashmap_t));

    if (map == NULL)
        return (NULL);
    if (capacity < 2)
        capacity = 2;
    map->capacity = capacity;
    map->size = 0;
    map->keys = dcalloc(capacity, sizeof(void *));
    map->values = dcalloc(capacity, sizeof(void *));
    if (map->keys == NULL || map->values == NULL)
        return (NULL);
    map->hasher = hasher != NULL ? hasher : &no_hashing_fnc;
    return (map);
}