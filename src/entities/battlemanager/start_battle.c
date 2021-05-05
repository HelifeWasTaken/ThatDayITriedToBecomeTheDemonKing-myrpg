/*
** EPITECH PROJECT, 2021
** start_battle
** File description:
** Source code
*/
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "myrpg/scenes.h"

int start_battle(game_t *game, int boss_id)
{
    int exit_code;
    sfView *view = game->view;
    game_state_t *state = game->state;

    state->last_boss_id = boss_id;
    estrncpy(state->save.map_id, game->scene->world_file, 255);
    exit_code = await_scene(game, BATTLE_SCENE);
    set_game_view(game, view);
    if (exit_code == 84)
        return (-1);
    return (exit_code);
}