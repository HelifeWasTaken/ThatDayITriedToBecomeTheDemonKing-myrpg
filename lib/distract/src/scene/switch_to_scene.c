/*
** EPITECH PROJECT, 2020
** load_scene
** File description:
** Source code
*/
#include "distract/game.h"

void switch_to_scene(game_t *game, int id)
{
    game->scene->in_exit_state = true;
    game->scene->pending_scene_id = id;
}