/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_at
*/

#include <erty/json.h>

OPT(json_bucket) json_bucket_get_at(struct json_bucket *self, size_t i)
{
    struct json_bucket_data *ptr = self->list;
    json_tuple_bucket_t data = {0};

    for (size_t idx = 0; ptr && idx < i; idx++)
        ptr = ptr->next;
    return (ptr ? OK(json_bucket, ptr->data) :
        (OPT(json_bucket)){.is_ok = false, .value = data});
}