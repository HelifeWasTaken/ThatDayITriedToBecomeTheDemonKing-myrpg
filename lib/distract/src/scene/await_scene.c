/*
** EPITECH PROJECT, 2021
** push_scene
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/resources.h"
#include "distract/scene.h"
#include "distract/sound.h"
#include <stdio.h>

static void pause_music(scene_t *parent_scene)
{
    hashmap_t *hashmap = parent_scene->resources;
    struct hashmap_list *list = NULL;
    resource_t *resources = NULL;;

    for (size_t i = 0; i < parent_scene->resources->capacity; i++) {
        list = hashmap->bucket[i].data;
        if (list == NULL)
            continue;
        resources = list->value;
        if (resources->type == R_MUSIC)
            sfMusic_pause(resources->music);
        else if (resources->type == R_SOUND)
            sfSound_pause(resources->sound);
    }
}

static void resume_music(game_t *game, scene_t *parent_scene)
{
    hashmap_t *hashmap = parent_scene->resources;
    struct hashmap_list *list = NULL;
    resource_t *resources = NULL;;

    for (size_t i = 0; i < parent_scene->resources->capacity; i++) {
        list = hashmap->bucket[i].data;
        if (list == NULL)
            continue;
        resources = list->value;
        if (resources->type == R_MUSIC) {
            sfMusic_setVolume(resources->music, game->sound->volumes[0]);
            sfMusic_play(resources->music);
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
    reset_game_events(game);
    code = load_pending_scene(game);
    deallocate_scene(game->scene);
    reset_game_events(game);
    game->scene = parent_scene;
    resume_music(game, parent_scene);
    return (code);
}
