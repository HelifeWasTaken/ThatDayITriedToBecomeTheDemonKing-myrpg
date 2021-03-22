/*
** EPITECH PROJECT, 2020
** load_pending_scene
** File description:
** Source code
*/
#include "distract/scene.h"

int load_pending_scene(game_t *game)
{
    int id = game->scene->pending_scene_id;
    scene_info_t *scene_info = get_scene_info(game, id);

    game->is_paused = false;
    game->scene->id = id;
    game->scene->info = scene_info;
    game->scene->in_exit_state = false;
    game->scene->pending_scene_id = -1;
    return (scene_info->lifecycle(game));
}