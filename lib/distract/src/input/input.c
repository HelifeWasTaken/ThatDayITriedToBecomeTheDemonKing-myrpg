/*
** EPITECH PROJECT, 2021
** input
** File description:
** Source code
*/

#include <SFML/Window/Event.h>
#include <distract/game.h>
#include <distract/input.h>

void on_input(input_t *input, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed || event->type == sfEvtKeyReleased) {
        on_keyboard_input(input, &event->key);
    }
}

void update_input(input_t *input)
{
    update_keyboard_input(input);
}