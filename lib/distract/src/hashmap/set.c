/*
** EPITECH PROJECT, 2021
** distract
** File description:
** set
*/

#include "stdlib.h"
#include "distract/hashmap.h"
#include "distract/debug.h"

int hashmap_set(hashmap_t **self, void *key, void *value)
{
    size_t index = (*self)->hasher(*self, key) % (*self)->capacity;

    if (hashmap_get(*self, key) != NULL) {
        print_error("Called hashmap set with a key already existing");
        return (-1);
    }
    if (insert_hashmap_bucket_front(&(*self)->bucket[index].data,
                    &(struct hashmap_list){key, value, NULL}) == false) {
        print_error("Could not insert in hashmap");
        return (-1);
    }
    (*self)->size++;
    return (check_need_resize_hashmap(self));
}
