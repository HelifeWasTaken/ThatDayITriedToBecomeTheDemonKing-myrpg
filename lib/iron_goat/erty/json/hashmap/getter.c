/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_getter
*/

#include <erty/json.h>

OPT(json) json_hashmap_getter(struct json_hashmap **self, void *key)
{
    u64_t id = (*self)->hash(key) % (*self)->bucket_count;
    struct json unintialized = {0};

    for (struct json_bucket_data *ptr = (*self)->bucket[id].list;
        ptr != NULL; ptr = ptr->next)
        if (estrcmp((char *)key, ptr->data.key) == 0)
            return (OK(json, ptr->data.data));
    return ((struct my_opt_json){.is_ok = false, .value = unintialized});
}