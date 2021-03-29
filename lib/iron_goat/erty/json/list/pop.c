/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** json_bucket_pop
*/

#include <erty/json.h>

void json_bucket_remove_at_index(struct json_bucket *self, size_t index)
{
    struct json_bucket_data *ptr = self->list;

    for (size_t i = 0; i < index && ptr != NULL; ptr = ptr->next)
        i++;
    if (ptr == NULL)
        return;
    if (ptr->prev == NULL) {
        self->pop_front(self);
        return;
    }
    if (ptr->next == NULL) {
        ptr->prev->next = NULL;
        FREE_INTERNAL_BUCKET(self->_del, ptr);
        return;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    FREE_INTERNAL_BUCKET(self->_del, ptr);
}

void json_bucket_pop_clear(struct json_bucket *self)
{
    struct json_bucket_data *tmp = NULL;

    while (self->list != NULL) {
        tmp = self->list;
        self->list = self->list->next;
        FREE_INTERNAL_BUCKET(self->_del, tmp);
    }
}

void json_bucket_pop_head(struct json_bucket *self)
{
    struct json_bucket_data *tmp = self->list;

    if (self->list == NULL)
        return;
    self->list = self->list->next;
    FREE_INTERNAL_BUCKET(self->_del, tmp);
}

void json_bucket_pop_tail(struct json_bucket *self)
{
    struct json_bucket_data *ptr = self->list;

    if (ptr == NULL)
        return;
    for (; ptr->next; ptr = ptr->next);
    ptr->prev->next = NULL;
    FREE_INTERNAL_BUCKET(self->_del, ptr);
}
