/*
** EPITECH PROJECT, 2021
** insert
** File description:
** LibErty_json
*/

#include <erty/json.h>

bool json_hashmap_insert(struct json_hashmap **self,
                        struct tuple_json_bucket data)
{
    usize_t v = (*self)->hash(data.key) % (*self)->bucket_count;
    struct json_bucket_data *ptr = (*self)->bucket[v].list;
    usize_t count = 0;

    if (data.key == NULL)
        return (false);
    if ((*self)->get(self, data.key).is_ok == true) {
        DEBUG_PRINTF("ERROR: Key duplicate detected: %s", data.key);
        return (false);
    }
    if ((*self)->bucket[v].push_front(&(*self)->bucket[v], data) == true) {
        for (; ptr; ptr = ptr->next)
            count++;
        (*self)->size++;
        if ((count > 2 && ((*self)->size >=
            (*self)->bucket_count / 2)) || count > 3)
            return (json_hashmap_resizer(self));
        return (true);
    }
    return (false);
}