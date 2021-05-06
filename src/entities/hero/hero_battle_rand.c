/*
** EPITECH PROJECT, 2021
** hero_battle_rand
** File description:
** Source code
*/
#include "distract/game.h"
#include "distract/scene.h"
#include "erty/string/ecstring.h"
#include "myrpg/scenes.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include <SFML/Graphics/View.h>
#include <stdlib.h>

void start_battle(game_t *game, hero_t *hero UNUSED)
{
    int exit_code;
    sfView *view = game->view;
    game_state_t *state = game->state;

    estrncpy(state->save.map_id, game->scene->world_file, 255);
    exit_code = await_scene(game, BATTLE_SCENE);
    set_game_view(game, view);
    eprintf("%s", exit_code == 1 ? "You won!\n" : "You lose!\n");
}

void trigger_battle_rand(game_t *game, hero_t *hero)
{
    bool is_scene_attackable = (
        estrcmp(game->scene->world_file,
            "asset/map_asset/map_files/map_monde.json") == 0
        || estrcmp(game->scene->world_file,
            "asset/map_asset/map_files/desert.json") == 0
        || estrcmp(game->scene->world_file,
            "asset/map_asset/map_files/forest_map.json") == 0);

    if (hero->animation_clock->time > 0.01f
        && rand() % 250 == 0
        && is_scene_attackable && hero->cannot_be_attacked == false)
        start_battle(game, hero);
}