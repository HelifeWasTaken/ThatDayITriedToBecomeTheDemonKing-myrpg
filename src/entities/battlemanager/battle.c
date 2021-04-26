/*
** EPITECH PROJECT, 2021
** battle
** File description:
** Source code
*/

#include "distract/scene.h"
#include "distract/util.h"
#include "myrpg/battle.h"
#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include <SFML/Graphics/RenderWindow.h>

int create_battle(game_t *game, battlemanager_t *battlemanager)
{
    battlemanager->attack_clock = create_pausable_clock(game);
    D_ASSERT(battlemanager->attack_clock, NULL, "Can't create battle clock", -1)
    return (0);
}

static battle_opponent_t *get_first_enemy(battlemanager_t *battlemanager)
{
    for (int i = 0; i < battlemanager->enemies_count; i++) {
        if (battlemanager->enemies[i].health > 0)
            return &battlemanager->enemies[i];
    }
    return (NULL);
}

static void update_attack(game_t *game, battlemanager_t *battlemanager,
    battle_opponent_t *player, battle_opponent_t *enemy)
{
    if (battlemanager->is_player_turn) {
        if (battlemanager->hud->selected_spell_id != -1) {
            attack_opponent(game, player, enemy,
                &player->spells[battlemanager->hud->selected_spell_id]);
            battlemanager->hud->selected_spell_id = -1;
            battlemanager->is_player_turn = false;
            battlemanager->attack_clock->time = 0;
        }
    } else {
        attack_opponent(game, enemy, player, &enemy->spells[0]);
        battlemanager->attack_clock->time = 0;
        battlemanager->is_player_turn = true;
    }
}

void update_battle(game_t *game UNUSED, battlemanager_t *battlemanager)
{
    battle_opponent_t *enemy = get_first_enemy(battlemanager);
    battle_opponent_t *player = &battlemanager->friends[0];

    if (battlemanager->attack_clock->time > 1.0f) {
        if (enemy == NULL || player->health <= 0) {
            battlemanager->exit_code = (player->health <= 0) ? 0 : 1;
            switch_to_scene(game, -1);
            return;
        }
        update_attack(game, battlemanager, player, enemy);
    }
    tick_pausable_clock(battlemanager->attack_clock);
}

void destroy_battle(game_t *game UNUSED, battlemanager_t *battlemanager)
{
    destroy_pausable_clock(battlemanager->attack_clock);
}