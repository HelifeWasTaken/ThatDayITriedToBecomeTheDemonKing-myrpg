/*
** EPITECH PROJECT, 2021
** distract
** File description:
** create
*/

#include "stdlib.h"
#include <distract/hashmap.h>
#include <distract/util.h>
#include <distract/debug.h>

static size_t no_hashing_fnc(hashmap_t *map, void *key)
{
    return (((size_t) key) % map->capacity);
}

hashmap_t *hashmap_create(size_t capacity,
    size_t (*hasher)(hashmap_t *map, void *key))
{
    hashmap_t *map = dcalloc(1, sizeof(hashmap_t));

    if (map == NULL) {
        print_error("Hashmap ressource could not be initted");
        return (NULL);
    }
    if (capacity < 2)
        capacity = 2;
    map->capacity = capacity;
    map->size = 0;
    map->bucket = dcalloc(capacity, sizeof(struct hashmap_bucket));
    if (map->bucket == NULL) {
        print_error("Buckets and could not be initted");
        return (NULL);
    }
    map->hasher = hasher != NULL ? hasher : &no_hashing_fnc;
    return (map);
}
