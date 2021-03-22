/*
** EPITECH PROJECT, 2020
** set_pending_scene
** File description:
** Source code
*/
#include "distract/scene.h"

void set_pending_scene(game_t *game, int id)
{
    game->scene->pending_scene_id = id;
}