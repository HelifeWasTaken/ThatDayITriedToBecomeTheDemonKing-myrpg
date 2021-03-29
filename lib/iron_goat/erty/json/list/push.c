/*
** EPITECH PROJECT, 2021
** push_fun
** File description:
** LibErty_Json
*/

#include <erty/json.h>

bool json_bucket_push_front(struct json_bucket *self, json_tuple_bucket_t data)
{
    struct json_bucket_data *new_node = create_json_bucket_node(data);

    if (new_node == NULL)
        return (false);
    new_node->next = self->list;
    if (self->list != NULL)
        self->list->prev = new_node;
    self->list = new_node;
    return (true);
}

bool json_bucket_push_back(struct json_bucket *self, json_tuple_bucket_t data)
{
    struct json_bucket_data *mv_ptr = self->list;

    if (self->list == NULL)
        return (self->push_front(self, data));
    for (; mv_ptr->next != NULL; mv_ptr = mv_ptr->next);
    if ((mv_ptr->next = create_json_bucket_node(data)) == NULL)
        return (false);
    mv_ptr->next->prev = mv_ptr;
    return (true);
}

static bool json_bucket_append_at_index_sub_fun(struct json_bucket_data *self,
    json_tuple_bucket_t data)
{
    struct json_bucket_data *new_node = create_json_bucket_node(data);
    struct json_bucket_data *next = self->next;

    if (new_node == NULL)
        return (false);
    new_node->next = next;
    self->next = new_node;
    return (true);
}

bool json_bucket_append_at_index(struct json_bucket *self,
                                json_tuple_bucket_t data, size_t index)
{
    struct json_bucket_data *mv_ptr = self->list;
    size_t i = 0;

    if (index == 0)
        return (self->push_front(self, data));
    if (mv_ptr == NULL)
        return (false);
    for (; mv_ptr->next && i < index - 1; i++)
        mv_ptr = mv_ptr->next;
    if (mv_ptr->next == NULL) {
        DEBUG_ASSERT("LibSearph", "ERROR: Reached end before index");
        return (false);
    }
    return (json_bucket_append_at_index_sub_fun(mv_ptr, data));
}