/*
** EPITECH PROJECT, 2020
** create_entity
** File description:
** Source code
*/

#include "SFML/System.h"
#include "distract/debug.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "stdlib.h"

static void set_defaults(int type, entity_t *entity,
    entity_info_t *info)
{
    entity->use_multithreading = false;
    entity->threadinfo = NULL;
    entity->prev = NULL;
    entity->next = NULL;
    entity->z = 0;
    entity->pos = (sfVector2f) { 0, 0 };
    entity->info = info;
    entity->type = type;
    entity->do_collide_point = NULL;
}

static void thread_update(void *data)
{
    struct thread_info *threadinfo = (struct thread_info *)data;
    threadinfo->entity->info->update(threadinfo->game, threadinfo->entity);
}

static void setup_multithreading(game_t *game, entity_t *entity)
{
    entity->threadinfo = malloc(sizeof(struct thread_info));
    if (entity->threadinfo != NULL) {
        entity->threadinfo->game = game;
        entity->threadinfo->entity = entity;
    }
    entity->threadinfo->thread = sfThread_create(&thread_update,
        entity->threadinfo);
    if (entity->threadinfo == NULL || entity->threadinfo->thread == NULL)
        entity->use_multithreading = false;
}

entity_t *create_entity(game_t *game, int type)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity_info_t *info = get_entity_info(game, type);

    if (info == NULL)
        print_error("Entity is not registered!");
    if (entity == NULL || info == NULL)
        return (NULL);
    set_defaults(type, entity, info);
    if (info->create != NULL) {
        info->create(game, entity);
        if (entity->instance == NULL)
            return (NULL);
        if (entity->use_multithreading)
            setup_multithreading(game, entity);
    }
    add_to_entities(game, entity);
    return (entity);
}