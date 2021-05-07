/*
** EPITECH PROJECT, 2020
** load_scene
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/util.h"

void switch_to_scene(game_t *game, int id)
{
    game->scene->in_exit_state = true;
    game->scene->pending_scene_id = id;
}

void switch_to_world(game_t *game, char const *file)
{
    game->scene->in_exit_state = true;

    if (dstrcmp(file, game->scene->world_file) == 0) {
        game->scene->in_exit_state = false;
        return;
    }
    if (file == NULL)
        game->scene->pending_scene_id = -1;
    else
        game->scene->pending_scene_id = game->scene->id;
    game->scene->world_file = dstrdup(file);
}