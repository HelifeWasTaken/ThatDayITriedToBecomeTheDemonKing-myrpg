/*
** EPITECH PROJECT, 2021
** distract
** File description:
** index
*/

#include "stdlib.h"
#include "distract/hashmap.h"

void *hashmap_getindex(hashmap_t *map, void *key)
{
    struct hashmap_list *list = map->bucket[
        map->hasher(map, key) % map->capacity].data;

    for (; list; list = list->next)
        if (dstrcmp(key, list->key) == 0)
            return (list->value);
    return (NULL);
}
