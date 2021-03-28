/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** insert_push_vector_json
*/

#include <erty/json.h>

isize_t json_vector_push_back(struct json_array **self, struct json add)
{
    if ((*self)->a_size == (*self)->size) {
        (*self)->a_size += (*self)->a_size ? (*self)->a_size / 10 : 10;
        if ((*self)->size)
            (*self)->data = erealloc((*self)->data,
                sizeof(struct json) * (*self)->size,
                sizeof(struct json) * (*self)->a_size);
        else
            (*self)->data = emalloc(
                sizeof(struct json) * (*self)->a_size);
        if ((*self)->data == NULL)
            return (-1);
    }
    ememcpy(&(*self)->data[(*self)->size], &add, sizeof(struct json));
    (*self)->size++;
    return ((*self)->size);
}
