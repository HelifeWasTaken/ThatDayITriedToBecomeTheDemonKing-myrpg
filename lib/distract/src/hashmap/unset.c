/*
** EPITECH PROJECT, 2021
** distract
** File description:
** unset
*/

#include "stdlib.h"
#include "distract/hashmap.h"

void hashmap_unset(hashmap_t **self, void *key)
{
    size_t index = (*self)->hasher(*self, key);
    struct hashmap_list *list = (*self)->bucket[index].data;
    struct hashmap_list *prev = NULL;

    for (; list; list = list->next) {
        if (dstrcmp(key, list->key) == 0) {
            if (prev == NULL) {
                free(list);
                list = NULL;
                (*self)->bucket[index].data = NULL;
            } else {
                prev->next = list->next;
                free(list);
                list = NULL;
            }
        }
        prev = list;
    }
}
