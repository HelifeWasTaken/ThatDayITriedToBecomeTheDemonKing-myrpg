/*
** EPITECH PROJECT, 2020
** has_pending_scene
** File description:
** Source code
*/
#include "stdbool.h"
#include "distract/game.h"

bool has_pending_scene(game_t *game)
{
    return (sfRenderWindow_isOpen(game->window)
            && game->scene->pending_scene_id != -1
            && !game->is_closing);
}