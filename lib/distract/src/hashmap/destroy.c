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
    free(map->values);
    free(map->keys);
    free(map);
}