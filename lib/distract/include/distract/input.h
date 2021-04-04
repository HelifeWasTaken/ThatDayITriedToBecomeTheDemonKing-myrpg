/*
** EPITECH PROJECT, 2021
** input
** File description:
** Source code
*/

#ifndef DEBA9E30_E2DE_4A8C_9547_32CE913F5176
#define DEBA9E30_E2DE_4A8C_9547_32CE913F5176

#include <SFML/Window/Event.h>
#include <stdbool.h>

#define GET_INPUT_KEY(code) \
    get_input_key(&game->input, (code))

#define WAS_KEY_DOWN(code) \
    (get_input_key(&game->input, (code)).was_pressed)

#define WAS_KEY_UP(code) \
    (!get_input_key(&game->input, (code)).was_pressed)

#define IS_KEY_DOWN(code) \
    (get_input_key(&game->input, (code)).is_pressed)

#define IS_KEY_UP(code) \
    (!get_input_key(&game->input, (code)).is_pressed)

#define IS_KEY_PRESS_FRAME(code) \
    (get_input_key(&game->input, (code)).is_being_pressed)

#define IS_KEY_RELEASE_FRAME(code) \
    (get_input_key(&game->input, (code)).is_being_released)

typedef struct keyboard_input {
    bool is_being_pressed;
    bool is_pressed;
    bool is_being_released;
    bool was_pressed;
} keyboard_input_t;

typedef struct input {
    struct keyboard_input keys[sfKeyCount];
} input_t;

void on_keyboard_input(input_t *input, sfKeyEvent *event);

void update_input(input_t *input);

void on_input(input_t *input, sfEvent *event);

void update_keyboard_input(input_t *input);

keyboard_input_t get_input_key(input_t *input, sfKeyCode keycode);

#endif /* DEBA9E30_E2DE_4A8C_9547_32CE913F5176 */
