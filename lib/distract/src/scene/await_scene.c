/*
** EPITECH PROJECT, 2021
** push_scene
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/resources.h"
#include "distract/scene.h"
#include <stdio.h>

static void pause_music(scene_t *parent_scene)
{
    resource_t **resources = (resource_t **)parent_scene->resources->values;

    for (size_t i = 0; i < parent_scene->resources->capacity; i++) {
        if (resources[i] == NULL)
            continue;
        if(resources[i]->type == R_MUSIC) {
            sfMusic_pause(resources[i]->music);
        }
        if(resources[i]->type == R_SOUND) {
            sfSound_pause(resources[i]->sound);
        }
    }
}

static void resume_music(scene_t *parent_scene)
{
    resource_t **resources = (resource_t **)parent_scene->resources->values;

    for (size_t i = 0; i < parent_scene->resources->capacity; i++) {
        if (resources[i] == NULL)
            continue;
        if(resources[i]->type == R_MUSIC) {
            sfMusic_play(resources[i]->music);
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
    resume_music(parent_scene);
    return (code);
}