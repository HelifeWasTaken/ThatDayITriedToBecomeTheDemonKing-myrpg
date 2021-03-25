/*
** EPITECH PROJECT, 2020
** game
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/hashmap.h"
#include "stdlib.h"

static size_t hash_resource_key(hashmap_t *map, void *key)
{
    char *str = (void *)key;
    size_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return (hash % map->capacity);
}

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    scene_t *scene = malloc(sizeof(scene_t));

    if (game == NULL || scene == NULL)
        return (NULL);
    game->window = NULL;
    game->state = NULL;
    game->is_paused = false;
    game->scenes = NULL;
    game->scene = scene;
    game->scene->entities = NULL;
    game->scene->resources = hashmap_create(50, &hash_resource_key);
    game->scene->gui_elements = NULL;
    game->scene->id = -1;
    game->scene->pending_scene_id = -1;
    game->entities = NULL;
    return (game);
}

static void destroy_entity_infos(game_t *game)
{
    entity_info_t *entity_info = game->entities;
    entity_info_t *next = NULL;

    while (entity_info != NULL) {
        next = entity_info->next;
        free(entity_info);
        entity_info = next;
    }
    game->entities = NULL;
}

static void destroy_scene_infos(game_t *game)
{
    scene_info_t *scene_info = game->scenes;
    scene_info_t *next = NULL;

    while (scene_info != NULL) {
        next = scene_info->next;
        free(scene_info);
        scene_info = next;
    }
    game->scenes = NULL;
}

void destroy_game(game_t *game)
{
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    destroy_scene(game, true);
    hashmap_destroy(game->scene->resources);
    destroy_entity_infos(game);
    destroy_scene_infos(game);
    free(game->scene);
    free(game);
}