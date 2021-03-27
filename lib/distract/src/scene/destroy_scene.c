/*
** EPITECH PROJECT, 2020
** destroy_scene
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/hashmap.h"
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
    hashmap_t *map = game->scene->resources;

    if (map == NULL)
        return;
    for (size_t i = 0; i < map->capacity; i++) {
        if (map->values[i] != NULL) {
            destroy_resource(game, map->values[i]);
        }
    }
    game->scene->resources = hashmap_create(map->capacity / 2, map->hasher);
    hashmap_destroy(map);
}

void destroy_scene(game_t *game, bool destroy_resources)
{
    if (game->scene)
        destroy_scene_entities(game);
    if (destroy_resources) {
        destroy_scene_resources(game);
    }
}
