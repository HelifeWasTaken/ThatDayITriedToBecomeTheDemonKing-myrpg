/*
** EPITECH PROJECT, 2021
** cinema
** File description:
** cinema
*/

#include "myrpg/cinema.h"

static struct cinema *add_cinema_node(struct cinema *data)
{
    struct cinema *cine = malloc(sizeof(struct cinema));

    if (cine == NULL)
        return (NULL);
    cine->type = data->type;
    cine->cycle_count = data->cycle_count;
    cine->next = NULL;
    cine->u = data->u;
    return (cine);
}

bool push_back_cinema(struct cinema **head, struct cinema *data)
{
    struct cinema *tmp = *head;

    if (*head == NULL) {
        *head = add_cinema_node(data);
        return (*head != NULL);
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = add_cinema_node(data);
    return (tmp->next != NULL);
}

void pop_front_cinema(game_t *game, struct cinema **head)
{
    struct cinema *ptr = *head;

    if (ptr == NULL)
        return;
    *head = (*head)->next;
    if (ptr->type == DISP_TEXT && ptr->u.disp.dlg.messages != NULL) {
        free_esplit(ptr->u.disp.dlg.messages);
        hide_dialog(game, ptr->u.disp.dlg.box);
    } else if (ptr->type == SWITCH_SCENE_CINEMATIC)
        free(ptr->u.scene);
    free(ptr);
}
