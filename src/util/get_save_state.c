/*
** EPITECH PROJECT, 2021
** get
** File description:
** savestae
*/

#include "myrpg/game.h"
#include "myrpg/state.h"

game_state_t *get_game_state(game_t *game)
{
    return (game->state);
}