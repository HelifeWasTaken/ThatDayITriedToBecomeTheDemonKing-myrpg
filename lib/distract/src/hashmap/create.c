/*
** EPITECH PROJECT, 2021
** distract
** File description:
** create
*/

#include "stdlib.h"
#include <distract/hashmap.h>

static size_t no_hashing_fnc(hashmap_t *map, void *key)
{
    return (((size_t) key) % map->capacity);
}

static void *zeroed_malloc(size_t size)
{
    void *ptr = malloc(size);
    unsigned char *bytes = (unsigned char *)ptr;
    
    while (size) {
        bytes[size - 1] = 0;
        size--;
    }
    return (ptr);
}

hashmap_t *hashmap_create(size_t capacity,
    size_t (*hasher)(hashmap_t *map, void *key))
{
    hashmap_t *map = zeroed_malloc(sizeof(hashmap_t));

    if (capacity < 2)
        capacity = 2;
    map->capacity = capacity;
    map->size = 0;
    map->keys = zeroed_malloc(sizeof(void *) * capacity);
    map->values = zeroed_malloc(sizeof(void *) * capacity);
    map->hasher = hasher != NULL ? hasher : &no_hashing_fnc;
    return (map);
}