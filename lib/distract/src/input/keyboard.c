/*
** EPITECH PROJECT, 2021
** keyboard
** File description:
** Source code
*/

#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <distract/game.h>
#include <stdio.h>
#include "distract/input.h"

void on_keyboard_input(input_t *input, sfKeyEvent *event)
{
    keyboard_input_t *key;

    if (event->code == sfKeyUnknown)
        return;
    key = &input->keys[event->code];
    if (event->type == sfEvtKeyPressed && !key->was_pressed) {
        key->is_being_pressed = true;
        key->is_being_released = false;
        key->is_pressed = true;
        key->was_pressed = false;
    }
    if (event->type == sfEvtKeyReleased && key->was_pressed) {
        key->is_being_pressed = false;
        key->is_being_released = true;
        key->is_pressed = false;
        key->was_pressed = true;
    }
}

void update_keyboard_input(input_t *input)
{
    keyboard_input_t *key;

    for (int i = 0; i < sfKeyCount; i++) {
        key = &input->keys[i];
        key->is_pressed = sfKeyboard_isKeyPressed(i);
        if (!key->was_pressed && key->is_pressed) {
            key->is_being_pressed = false;
            key->was_pressed = true;
        }
        if (key->was_pressed && !key->is_pressed) {
            key->is_being_released = false;
            key->was_pressed = false;
        }
    }
}

keyboard_input_t get_input_key(input_t *input, sfKeyCode keycode)
{
    if (input == NULL || keycode == sfKeyUnknown)
        return ((keyboard_input_t) {0});
    return input->keys[keycode];
}
