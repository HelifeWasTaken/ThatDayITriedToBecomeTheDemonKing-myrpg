/*
** EPITECH PROJECT, 2021
** reset_game_events
** File description:
** Source code
*/

#include "distract/game.h"
#include <SFML/Window/Keyboard.h>

void reset_game_events(game_t *game)
{
    sfEvent e;
    sfKeyCode i;

    while (sfRenderWindow_pollEvent(game->window, &e));
    for (i = 0; i < sfKeyCount; i++) {
        game->input.keys[i].is_being_pressed = false;
        game->input.keys[i].is_being_released = false;
        game->input.keys[i].is_pressed = sfKeyboard_isKeyPressed(i);
        game->input.keys[i].was_pressed = false;
    }
}