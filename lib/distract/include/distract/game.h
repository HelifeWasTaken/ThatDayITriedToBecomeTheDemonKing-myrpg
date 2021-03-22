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

game_t *create_game(void);
void destroy_game(game_t *game);
void close_game(game_t *game);

typedef struct pausable_clock {
    game_t *game;
    sfClock *frame_clock;
    float time;
    sfBool is_paused;
    sfBool has_game_pause;
} pausable_clock_t;

pausable_clock_t *create_pausable_clock(game_t *game);
float tick_pausable_clock(pausable_clock_t *clock);
void destroy_pausable_clock(pausable_clock_t *clock);
void restart_pausable_clock(pausable_clock_t *clock);

#endif //DISTRACT_GAME_H