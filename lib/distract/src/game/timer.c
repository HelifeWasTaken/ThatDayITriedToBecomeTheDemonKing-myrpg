/*
** EPITECH PROJECT, 2021
** timer
** File description:
** Source code
*/
#include "distract/game.h"
#include "SFML/Graphics.h"
#include "stdlib.h"

pausable_clock_t *create_pausable_clock(game_t *game)
{
    pausable_clock_t *clock = malloc(sizeof(pausable_clock_t));

    if (clock == NULL)
        return (NULL);
    clock->game = game;
    clock->has_game_pause = true;
    clock->is_paused = false;
    clock->time = 0;
    clock->frame_clock = sfClock_create();
    return (clock);
}

float tick_pausable_clock(pausable_clock_t *clock)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(clock->frame_clock));

    if (!clock->is_paused
        && (!clock->has_game_pause || !clock->game->is_paused)) {
            clock->time += time;
            sfClock_restart(clock->frame_clock);
            return (time);
    }
    sfClock_restart(clock->frame_clock);
    return (0);
}

void destroy_pausable_clock(pausable_clock_t *clock)
{
    sfClock_destroy(clock->frame_clock);
    free(clock);
}

void restart_pausable_clock(pausable_clock_t *clock)
{
    clock->time = 0;
    sfClock_restart(clock->frame_clock);
}