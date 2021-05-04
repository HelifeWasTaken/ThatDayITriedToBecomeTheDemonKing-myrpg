/*
** EPITECH PROJECT, 2021
** distract
** File description:
** hashmap
*/

#include "stdlib.h"
#include "distract/hashmap.h"

static void free_buckets(struct hashmap_list *bucket)
{
    if (bucket == NULL)
        return;
    free_buckets(bucket->next);
    free(bucket);
}

void hashmap_destroy(hashmap_t *map)
{
    if (map) {
        for (size_t i = 0; i < map->capacity; i++)
            free_buckets(map->bucket[i].data);
        free(map->bucket);
        free(map);
    }
}
