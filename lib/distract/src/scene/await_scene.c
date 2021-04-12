/*
** EPITECH PROJECT, 2021
** push_scene
** File description:
** Source code
*/

#include "distract/scene.h"
#include <stdio.h>

int await_scene(game_t *game, int scene_id)
{
    int code;
    scene_t *parent_scene = game->scene;

    game->scene = allocate_scene();
    if (game->scene == NULL)
        return (-1);
    set_pending_scene(game, scene_id);
    code = load_pending_scene(game);
    printf("hahah");
    deallocate_scene(game->scene);
    game->scene = parent_scene;
    return (code);
}