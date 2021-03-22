/*
** EPITECH PROJECT, 2020
** draw_scene
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "stdio.h"

void draw_scene(game_t *game)
{
    entity_t *entity = game->scene->entities;

    while (entity != NULL) {
        draw_entity(game, entity);
        entity = entity->next;
    }
}