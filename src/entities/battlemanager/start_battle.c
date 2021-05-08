/*
** EPITECH PROJECT, 2021
** start_battle
** File description:
** Source code
*/
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/scene.h"
#include "myrpg/scenes.h"

static void trigger_battle_win(game_t *game, int boss_id)
{
    game_state_t *state = game->state;

    state->save.player_xp += 35;
    if (state->save.player_xp >= 100) {
        state->save.player_xp = 0;
        state->save.player_lv += 1;
    }
    state->save.levels_done[boss_id] = true;
    if (boss_id == 3) {
        for (int i = 0; i < 3; i++)
            state->save.levels_done[i] = true;
        switch_to_scene(game, PLAY_SCENE);
    }
}

static void trigger_battle_lose(game_t *game)
{
    switch_to_scene(game, MENU_SCENE);
}

int start_battle(game_t *game, int boss_id)
{
    int exit_code;
    sfView *view = game->view;
    game_state_t *state = game->state;
    int hp = get_game_state(game)->save.player_hp;

    state->last_boss_id = boss_id;
    estrncpy(state->save.map_id, game->scene->world_file, 255);
    exit_code = await_scene(game, BATTLE_SCENE);
    set_game_view(game, view);
    state->save.player_hp = hp;
    if (exit_code == 0)
        trigger_battle_lose(game);
    if (exit_code == 1)
        trigger_battle_win(game, boss_id);
    if (exit_code == 84)
        return (-1);
    return (exit_code);
}