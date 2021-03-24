/*
** EPITECH PROJECT, 2020
** entity
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "stdlib.h"
#include "SFML/System.h"
#include <SFML/System/Thread.h>

entity_t *get_next_entity_of_type(entity_t *entity, int type)
{
    if (entity == NULL)
        return (NULL);
    entity = entity->next;
    if (entity == NULL)
        return (NULL);
    for (; entity != NULL; entity = entity->next) {
        if (entity->type == type)
            return (entity);
    }
    return (NULL);
}

void update_entity(game_t *game, entity_t *entity)
{
    if (entity->info->update != NULL) {
        entity->info->update(game, entity);
    }
}

void update_entity_async(game_t *game UNUSED, entity_t *entity)
{
    if (entity->info->update != NULL) {
        sfThread_launch(entity->thread);
    }
}

void draw_entity(game_t *game, entity_t *entity)
{
    if (entity->info->draw != NULL)
        entity->info->draw(game, entity);
}

void destroy_entity(game_t *game, entity_t *entity)
{
    if (entity->info->destroy != NULL)
        entity->info->destroy(game, entity);
    if (entity->thread != NULL) {
        sfThread_terminate(entity->thread);
        sfThread_destroy(entity->thread);
    }
    if (game->scene->entities == entity)
        game->scene->entities = entity->next;
    if (entity->prev != NULL)
        entity->prev->next = entity->next;
    if (entity->next != NULL)
        entity->next->prev = entity->prev;
    entity->info = NULL;
    free(entity);
}