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
    eprintf("%s", exit_code == 1 ? "You won!\n" : "You lose!\n");
}

void trigger_battle_rand(game_t *game, hero_t *hero)
{
    bool is_scene_attackable = (estrcmp(game->scene->world_file,
            "asset/map_asset/map_files/map_monde.json") == 0);

    if (hero->animation_clock->time > 0.01f
        && rand() % 250 == 0
        && is_scene_attackable)
        start_battle(game, hero);
}