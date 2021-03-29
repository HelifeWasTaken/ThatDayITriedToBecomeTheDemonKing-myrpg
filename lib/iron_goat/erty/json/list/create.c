/*
** EPITECH PROJECT, 2021
** josn
** File description:
** create_bucket_node
*/

#include <erty/json.h>

struct json_bucket_data *create_json_bucket_node(json_tuple_bucket_t data)
{
    struct json_bucket_data *new_node = NULL;

    EXCALLOC(new_node, sizeof(struct json_bucket_data), 1, NULL);
    new_node->data = data;
    return (new_node);
}