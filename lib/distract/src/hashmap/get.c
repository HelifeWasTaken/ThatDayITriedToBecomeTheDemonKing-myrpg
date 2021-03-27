/*
** EPITECH PROJECT, 2021
** distract
** File description:
** get
*/

#include "distract/hashmap.h"

void *hashmap_get(hashmap_t *map, void *key)
{
    return (map->values[hashmap_getindex(map, key)]);
}
