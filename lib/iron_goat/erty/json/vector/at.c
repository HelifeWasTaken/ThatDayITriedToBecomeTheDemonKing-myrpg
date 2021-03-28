/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_vector_at
*/

#include <erty/json.h>

OPT(json) json_vector_at(struct json_array **self, usize_t idx)
{
    struct json none UNUSED = {0};

    UNINITIALIZED(none);
    return ((idx > (*self)->size) ? EXPLICIT_ERR(json, none) :
        OK(json, (*self)->data[idx]));
}