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
#include "distract/util.h"
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

    if (entity->threadinfo == NULL) {
        entity->use_multithreading = false;
        return;
    }
    entity->threadinfo->game = game;
    entity->threadinfo->entity = entity;
    entity->threadinfo->thread = sfThread_create(&thread_update,
        entity->threadinfo);
    if (entity->threadinfo->thread == NULL)
        entity->use_multithreading = false;
}

entity_t *create_entity(game_t *game, int type)
{
    entity_t *entity = dcalloc(sizeof(entity_t), 1);
    entity_info_t *info = get_entity_info(game, type);

    D_ASSERT(info, NULL, "Entity is not registered", false);
    D_ASSERT(entity, NULL, "Entity creation failed", false);
    if (entity == NULL || info == NULL) {
        print_error("Entity creation failed");
        return (NULL);
    }
    set_defaults(type, entity, info);
    if (info->create != NULL) {
        D_ASSERT(info->create(game, entity), false,
            "Create failed", false);
        D_ASSERT(entity->instance, NULL,
            "Entity instance creation failed", false);
        if (entity->use_multithreading)
            setup_multithreading(game, entity);
    }
    add_to_entities(game, entity);
    return (entity);
}
