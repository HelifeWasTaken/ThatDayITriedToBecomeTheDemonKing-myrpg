/*
** EPITECH PROJECT, 2021
** push_scene
** File description:
** Source code
*/

#include "distract/resources.h"
#include "distract/scene.h"
#include <stdio.h>

static void pause_music(scene_t *parent_scene)
{
    hashmap_t *hashmap = parent_scene->resources;
    struct hashmap_list *list = NULL;
    resource_t *resource = NULL;

    for (size_t i = 0; i < hashmap->capacity; i++) {
        list = hashmap->bucket[i].data;
        for (; list; list = list->next) {
            resource = list->value;
            if (resource == NULL)
                continue;
            if (resource->type == R_MUSIC)
                sfMusic_pause(resource->music);
            else if (resource->type == R_SOUND)
                sfSound_pause(resource->sound);
        }
    }
}

static void resume_music(scene_t *parent_scene)
{
    hashmap_t *hashmap = parent_scene->resources;
    struct hashmap_list *list = NULL;
    resource_t *resource = NULL;

    for (size_t i = 0; i < hashmap->capacity; i++) {
        list = hashmap->bucket[i].data;
        for (; list; list = list->next) {
            resource = list->value;
            if (resource == NULL)
                continue;
            else if (resource->type == R_MUSIC)
                sfMusic_play(resource->music);
        }
    }
}

int await_scene(game_t *game, int scene_id)
{
    int code;
    scene_t *parent_scene = game->scene;

    pause_music(parent_scene);
    game->scene = allocate_scene();
    if (game->scene == NULL)
        return (-1);
    set_pending_scene(game, scene_id);
    code = load_pending_scene(game);
    deallocate_scene(game->scene);
    game->scene = parent_scene;
    resume_music(parent_scene);
    return (code);
}
