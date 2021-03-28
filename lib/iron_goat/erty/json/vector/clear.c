/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_vector_erase_clear
*/

#include <erty/json.h>

void json_vector_clear(struct json_array **self)
{
    if ((*self)->_del)
        for (usize_t i = 0; i < (*self)->size; i++)
            (*self)->_del(&(*self)->data[i]);
    FREE((*self)->data);
    FREE(*self);
}

isize_t json_vector_erase(struct json_array **self, usize_t idx)
{
    struct json *tmp = NULL;
    size_t i = 0;

    if ((*self)->size <= idx)
        return (-1);
    EXCALLOC(tmp, sizeof(struct json), (*self)->size - 1, -1);
    for (; i != idx; i++)
        ememcpy(&tmp[i], &(*self)->data[i], sizeof(struct json));
    if ((*self)->_del)
        (*self)->_del(&(*self)->data[i]);
    i++;
    for (; i < (*self)->size; i++)
        ememcpy(&tmp[i], &(*self)->data[i], sizeof(struct json));
    FREE((*self)->data);
    (*self)->data = tmp;
    (*self)->size = i;
    return ((*self)->size);
}