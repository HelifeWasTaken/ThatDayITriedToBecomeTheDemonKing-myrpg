/*
** EPITECH PROJECT, 2021
** distract
** File description:
** resize
*/

#include "stdlib.h"
#include "distract/hashmap.h"

void hashmap_resize(hashmap_t **map_ptr)
{
    hashmap_t *map = *map_ptr;
    hashmap_t *new_map = hashmap_create(map->capacity * 2, map->hasher);
    
    for (size_t i = 0; i < map->capacity; i++) {
        if (map->keys[i] != NULL) {
            hashmap_set(&new_map, map->keys[i], map->values[i]);
        }
    }
    *map_ptr = new_map;
    hashmap_destroy(map);
}