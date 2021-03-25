/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** insert_push_vector_json
*/

#include <erty/json.h>

isize_t json_vector_insert(struct json_array **self,
                            struct json add, usize_t idx)
{
    struct json *tmp = NULL;
    usize_t i = 0;
    usize_t i2 = 0;

    if ((*self)->size <= idx)
        return (-1);
    EXCALLOC(tmp, sizeof(struct json), (*self)->size + 1, -1);
    for (; i != idx; i++)
        ememcpy(&tmp[i], &(*self)->data[i], sizeof(struct json));
    ememcpy(&tmp[i], &add, sizeof(struct json));
    i2 = i;
    for (i += 1; (*self)->size; i++) {
        ememcpy(&tmp[i], &(*self)->data[i2], sizeof(struct json));
        i2++;
    }
    FREE((*self)->data);
    (*self)->size = i;
    (*self)->data = tmp;
    return ((*self)->size);
}

isize_t json_vector_push_back(struct json_array **self, struct json add)
{
    struct json *tmp = NULL;

    EXCALLOC(tmp, sizeof(struct json), (*self)->size + 1, -1);
    for (usize_t i = 0; i < (*self)->size; i++)
        ememcpy(&tmp[i], &(*self)->data[i], sizeof(struct json));
    ememcpy(&tmp[(*self)->size], &add, sizeof(struct json));
    FREE((*self)->data);
    (*self)->data = tmp;
    (*self)->size++;
    return ((*self)->size);
}