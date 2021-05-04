/*
** EPITECH PROJECT, 2021
** push_scene
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/hashmap.h"
#include "distract/resources.h"
#include "distract/debug.h"
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
    struct hashmap_list *list = NULL;

    if (map == NULL)
        return;
    for (size_t i = 0; i < map->capacity; i++) {
        list = map->bucket[i].data;
        for (; list; list = list->next)
            destroy_resource(game, list->value);
    }
    game->scene->resources = hashmap_create(map->capacity / 2, map->hasher);
    if (game->scene->resources == NULL)
        print_error("Hashmap create failed in destroy scene ressources");
    hashmap_destroy(map);
}

void destroy_scene(game_t *game, bool destroy_resources)
{
    if (game->scene)
        destroy_scene_entities(game);
    if (destroy_resources)
        destroy_scene_resources(game);
}
