/*
** EPITECH PROJECT, 2020
** transmit_event_to_scene
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/input.h"
#include "distract/scene.h"
#include "distract/entity.h"

bool transmit_event_to_scene(game_t *game, sfEvent *event)
{
    entity_t *entity = game->scene->entities;
    entity_t *next;

    on_input(&game->input, event);
    for (; entity != NULL; entity = next) {
        next = entity->next;
        if (entity->info->handle_event != NULL) {
            if (entity->info->handle_event(game, entity, event))
                return (true);
        }
    }
    return (false);
}