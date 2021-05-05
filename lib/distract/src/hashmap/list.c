/*
** EPITECH PROJECT, 2021
** hashmaplist
** File description:
** list
*/

#include "distract/hashmap.h"
#include <stdlib.h>

struct hashmap_list *hashmap_create_node(struct hashmap_list *new)
{
    struct hashmap_list *tmp = malloc(sizeof(struct hashmap_list));

    if (tmp == NULL)
        return (NULL);
    tmp->key = new->key;
    tmp->value = new->value;
    tmp->next = NULL;
    return (tmp);
}

bool insert_hashmap_bucket_front(struct hashmap_list **list,
    struct hashmap_list *node)
{
    struct hashmap_list *new = hashmap_create_node(node);

    if (new == NULL)
        return (false);
    new->next = *list;
    *list = new;
    return (true);
}
