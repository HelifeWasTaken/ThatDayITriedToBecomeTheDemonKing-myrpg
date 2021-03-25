/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** hashmap_clear
*/

#include <erty/json.h>

void json_hashmap_clear(struct json_hashmap **self)
{
    for (usize_t i = 0; i < (*self)->bucket_count; i++)
        (*self)->bucket[i].clear(&(*self)->bucket[i]);
    FREE((*self)->bucket);
    FREE(*self);
}