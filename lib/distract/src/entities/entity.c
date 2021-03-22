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

entity_t *create_entity(game_t *game, int type)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity_info_t *info = get_entity_info(game, type);

    if (info == NULL)
        print_error("Entity is not registered!");
    entity->type = type;
    entity->prev = NULL;
    entity->next = NULL;
    entity->z = 0;
    entity->pos = (sfVector2f) { 0, 0 };
    entity->info = info;
    entity->type = type;
    entity->do_collide_point = NULL;
    if (info->create != NULL)
        info->create(game, entity);
    add_to_entities(game, entity);
    return (entity);
}

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
    if (entity->info->update != NULL)
        entity->info->update(game, entity);
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
    if (game->scene->entities == entity)
        game->scene->entities = entity->next;
    if (entity->prev != NULL)
        entity->prev->next = entity->next;
    if (entity->next != NULL)
        entity->next->prev = entity->prev;
    entity->info = NULL;
    free(entity);
}