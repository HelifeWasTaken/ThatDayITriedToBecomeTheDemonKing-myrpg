/*
** EPITECH PROJECT, 2020
** add_scene
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/scene.h"
#include "stdlib.h"
#include "stdarg.h"

void register_scene(game_t *game, int id, int (*lifecycle)(game_t *game))
{
    scene_info_t *scene = malloc(sizeof(scene_t));

    scene->id = id;
    scene->lifecycle = lifecycle;
    scene->next = game->scenes;
    game->scenes = scene;
}