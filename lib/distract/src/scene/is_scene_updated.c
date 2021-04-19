/*
** EPITECH PROJECT, 2020
** is_scene_updated
** File description:
** Source code
*/

#include "distract/game.h"

bool is_scene_updated(game_t *game)
{
    return (sfRenderWindow_isOpen(game->window)
        && !game->scene->in_exit_state
        && !game->is_closing);
}