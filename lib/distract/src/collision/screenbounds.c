/*
** EPITECH PROJECT, 2020
** screenbounds
** File description:
** Source code
*/

#include "SFML/Graphics.h"
#include "distract/game.h"

bool is_v2f_on_screen(game_t *game, sfVector2f vec)
{
    return (vec.x >= 0 && vec.y >= 0
        && vec.x <= game->mode.width && vec.y <= game->mode.height);
}

bool is_v2i_on_screen(game_t *game, sfVector2i vec)
{
    return (vec.x >= 0 && vec.y >= 0
        && vec.x <= (int)game->mode.width && vec.y <= (int)game->mode.height);
}