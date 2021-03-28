/*
** EPITECH PROJECT, 2020
** get_entity_info
** File description:
** Source code
*/
#include "distract/game.h"
#include "distract/entity.h"

entity_info_t *get_entity_info(game_t *game, int type)
{
    entity_info_t *entity = game->entities;

    for (; entity != NULL; entity = entity->next) {
        if (entity->type == type)
            return (entity);
    }
    return (NULL);
}
