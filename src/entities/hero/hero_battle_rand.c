/*
** EPITECH PROJECT, 2021
** hero_battle_rand
** File description:
** Source code
*/
#include "distract/game.h"
#include "distract/scene.h"
#include "myrpg/scenes.h"
#include "myrpg/entities.h"
#include <SFML/Graphics/View.h>
#include <stdlib.h>

void start_battle(game_t *game, hero_t *hero UNUSED)
{
    int exit_code;
    sfView *view = game->view;

    exit_code = await_scene(game, BATTLE_SCENE);
    set_game_view(game, view);
    eprintf("%s", exit_code == 1 ? "You won!" : "You lose!");
}

void trigger_battle_rand(game_t *game, hero_t *hero)
{
    if (hero->animation_clock->time > 0.01f && rand() % 10 == 0)
        start_battle(game, hero);
}