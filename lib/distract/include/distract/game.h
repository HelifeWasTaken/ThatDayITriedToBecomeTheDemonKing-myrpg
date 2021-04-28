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
#include "distract/input.h"

typedef struct game {

    ///
    /// CSFML Render Window
    ///
    sfRenderWindow *window;

    ///
    /// State renderer to draw
    ///
    sfRenderStates renderer;

    ///
    /// Scenes registry
    ///
    struct scene_info *scenes;

    ///
    /// Entities registry
    ///
    struct entity_info *entities;

    ///
    /// Current scene
    ///
    struct scene *scene;

    ///
    /// Sound emitter
    ///
    struct sound_emitter *sound;

    ///
    /// Screen video mode
    ///
    sfVideoMode mode;

    ///
    /// Is game paused?
    /// Mutable
    ///
    sfBool is_paused;

    ///
    /// Storage for global game state
    /// Mutable
    ///
    void *state;

    ///
    /// GUI view
    ///
    sfView *gui_view;

    ///
    /// World (non-GUI) view
    ///
    sfView *view;

    ///
    /// Input manager
    ///
    input_t input;

    ///
    /// Is the game in a closing state?
    ///
    bool is_closing;

    ///
    /// global game parameters
    ///
    ///
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

///
/// Set game view
///
void set_game_view(game_t *game, sfView *view);

///
/// Reset the game events.
///
void reset_game_events(game_t *game);

///
/// Basically an sfClock that can be paused
///
typedef struct pausable_clock {
    game_t *game;
    sfClock *frame_clock;

    ///
    /// Time since clock start.
    /// Don't forget to call `tick_pausable_clock(clock);` on each frame.
    /// Mutable
    ///
    float time;

    ///
    /// Is the clock paused?
    ///
    sfBool is_paused;

    ///
    /// Should the clock also be paused when the game is paused?
    ///
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