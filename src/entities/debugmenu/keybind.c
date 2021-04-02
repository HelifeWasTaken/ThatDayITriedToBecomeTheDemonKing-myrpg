/*
** EPITECH PROJECT, 2021
** keybind
** File description:
** Source code
*/

#include "distract/entity.h"
#include "distract/game.h"
#include "myrpg/entities.h"
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

void handle_debug_keybind(game_t *game UNUSED, sfKeyEvent *key UNUSED)
{
    if (key->control && key->code == sfKeyP)
        game->is_paused = !game->is_paused;
}
