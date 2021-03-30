/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_resizer_hashmap
*/

#include <erty/json.h>

static bool json_hashmap_resize_internal(struct json_hashmap **self,
    struct json_bucket **new_node, size_t i)
{
    u64_t id = 0;
    struct json_bucket_data *current = (*self)->bucket[i].list;
    struct json_bucket_data *nxt = NULL;

    while (current != NULL) {
        nxt = current->next;
        id = (*self)->hash(current->data.key) % (*self)->bucket_count;
        if (!(*new_node)[id].push_front(&(*new_node)[id],
            JSON_TUPLE(current->data.key, current->data.data)))
            return (false);
        FREE(current)
        current = nxt;
    }
    return (true);
}

bool json_hashmap_resizer(struct json_hashmap **self)
{
    struct json_bucket *n_buck = NULL;
    usize_t original_size = (*self)->bucket_count;

    (*self)->bucket_count *= 2;
    EXCALLOC(n_buck, sizeof(struct json_bucket), (*self)->bucket_count, false);
    for (usize_t i = 0; i < (*self)->bucket_count; i++)
        n_buck[i] = create_json_bucket(destroy_json_tuple);
    for (usize_t i = 0; i < original_size; i++)
        if (json_hashmap_resize_internal(self, &n_buck, i) == false)
            return (false);
    FREE((*self)->bucket);
    (*self)->bucket = n_buck;
    return (true);
}