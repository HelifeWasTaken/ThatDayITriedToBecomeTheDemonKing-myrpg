/*
** EPITECH PROJECT, 2021
** distract
** File description:
** get
*/

#include "distract/hashmap.h"

void *hashmap_get(hashmap_t *map, void *key)
{
  size_t index = hashmap_getindex(map, key);
  return (map->values[index]);
}