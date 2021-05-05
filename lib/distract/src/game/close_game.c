/*
** EPITECH PROJECT, 2020
** close_game
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/scene.h"

void close_game(game_t *game)
{
    game->is_closing = true;
}