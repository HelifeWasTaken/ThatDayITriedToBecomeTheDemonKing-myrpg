/*
** EPITECH PROJECT, 2020
** update_scene
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "stdio.h"

void update_scene(game_t *game)
{
    entity_t *entity = game->scene->entities;
    entity_t *next;

    while (entity != NULL) {
        next = entity->next;
        update_entity(game, entity);
        entity = next;
    }
}