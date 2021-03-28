/*
** EPITECH PROJECT, 2021
** distract
** File description:
** resize
*/

#include "stdlib.h"
#include "distract/hashmap.h"
#include "distract/debug.h"

int hashmap_resize(hashmap_t **map_ptr)
{
    hashmap_t *map = *map_ptr;
    hashmap_t *new_map = hashmap_create(map->capacity * 2, map->hasher);
    int code = 0;

    if (new_map == NULL) {
        print_error("Hashmap could not be reallocated");
        return (-1);
    }
    for (size_t i = 0; i < map->capacity; i++) {
        if (map->keys[i] != NULL) {
            code += hashmap_set(&new_map, map->keys[i], map->values[i]);
        }
    }
    if (code == 0) {
        *map_ptr = new_map;
        hashmap_destroy(map);
    }
    return (code < 0 ? -1 : 0);
}