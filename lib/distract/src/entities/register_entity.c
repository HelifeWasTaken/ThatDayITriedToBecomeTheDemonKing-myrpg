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
#include "stdio.h"
#include "unistd.h"
#include "stdarg.h"

void register_entity(game_t *game, entity_info_t *entity)
{
    entity_info_t *entity_info = malloc(sizeof(entity_info_t));
    if (entity == NULL)
        print_error("You're trying to register a null entity!");
    entity_info->type = entity->type;
    entity_info->create = entity->create;
    entity_info->destroy = entity->destroy;
    entity_info->draw = entity->draw;
    entity_info->update = entity->update;
    entity_info->handle_event = entity->handle_event;
    entity_info->next = game->entities;
    game->entities = entity_info;
}

void register_entities(game_t *game, entity_info_t **entities)
{
    entity_info_t *info;

    if (entities[0] == NULL)
        return;
    for (int i = 0; entities[i] != NULL; i++) {
        info = entities[i];
        register_entity(game, info);
    }
}