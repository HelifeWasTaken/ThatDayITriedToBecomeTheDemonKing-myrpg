/*
** EPITECH PROJECT, 2021
** get
** File description:
** savestae
*/

#include "myrpg/game.h"
#include "myrpg/state.h"

game_save_t *get_save_state(game_t *game)
{
    if (game->state == NULL)
        return (NULL);
    return (game->state);
}