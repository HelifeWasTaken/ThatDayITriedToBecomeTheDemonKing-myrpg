/*
** EPITECH PROJECT, 2020
** destroy_scene
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "stdlib.h"

static void destroy_scene_entities(game_t *game)
{
    entity_t *entity = game->scene->entities;
    entity_t *next = NULL;

    while (entity != NULL) {
        next = entity->next;
        destroy_entity(game, entity);
        entity = next;
    }
    game->scene->entities = NULL;
}

static void destroy_scene_resources(game_t *game)
{
    resource_t *resource = game->scene->resources;
    resource_t *next = NULL;

    while (resource != NULL) {
        next = resource->next;
        destroy_resource(game, resource);
        resource = next;
    }
    game->scene->resources = NULL;
}

void destroy_scene(game_t *game, bool destroy_resources)
{
    destroy_scene_entities(game);
    if (destroy_resources) {
        destroy_scene_resources(game);
    }
}