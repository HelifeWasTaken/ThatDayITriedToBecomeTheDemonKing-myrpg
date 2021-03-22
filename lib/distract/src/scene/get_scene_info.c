/*
** EPITECH PROJECT, 2020
** get_scene_info
** File description:
** Source code
*/
#include "distract/game.h"
#include "distract/scene.h"

scene_info_t *get_scene_info(game_t *game, int id)
{
    scene_info_t *scene = game->scenes;

    for (; scene != NULL; scene = scene->next) {
        if (scene->id == id)
            return (scene);
    }
    return (NULL);
}