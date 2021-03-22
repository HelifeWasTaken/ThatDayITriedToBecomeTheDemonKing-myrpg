/*
** EPITECH PROJECT, 2020
** game
** File description:
** Source code
*/

#ifndef DISTRACT_GAME_H
#define DISTRACT_GAME_H
#include "SFML/Window.h"
#include "SFML/Graphics.h"

typedef struct game {
    sfRenderWindow *window;
    struct scene_info *scenes;
    struct entity_info *entities;
    struct gui_element_info *gui_elements;
    struct scene *scene;
    sfVideoMode mode;
    sfBool is_paused;
    void *state;
} game_t;

#include "distract/scene.h"

///
/// Create a game instance.
///
game_t *create_game(void);

///
/// Destroy the game instance.
///
void destroy_game(game_t *game);

///
/// Close the game in a clean manner.
///
void close_game(game_t *game);

typedef struct pausable_clock {
    game_t *game;
    sfClock *frame_clock;
    float time;
    sfBool is_paused;
    sfBool has_game_pause;
} pausable_clock_t;

///
/// Create a clock that can be paused.
///
pausable_clock_t *create_pausable_clock(game_t *game);

///
/// Update the clock time.
///
float tick_pausable_clock(pausable_clock_t *clock);

///
/// Destroy the clock that can be paused.
///
void destroy_pausable_clock(pausable_clock_t *clock);

///
/// Restart the clock.
///
void restart_pausable_clock(pausable_clock_t *clock);

#endif //DISTRACT_GAME_H