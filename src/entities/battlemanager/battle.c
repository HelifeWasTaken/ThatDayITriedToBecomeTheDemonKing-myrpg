/*
** EPITECH PROJECT, 2021
** battle
** File description:
** Source code
*/

#include "distract/animable.h"
#include "distract/scene.h"
#include "distract/util.h"
#include "erty/estdlib.h"
#include "myrpg/battle.h"
#include "myrpg/state.h"
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
#include <SFML/Graphics/Sprite.h>

static const struct battle_background_pair BATTLE_BG[] = {
    {
        .world_id = "asset/map_asset/map_files/map_monde.json",
        .file = "asset/battlebg/world.png",
        .rect = { 0, 40, 1920, 1080 },
        .size = { 0.80, 0.89 }
    },
    {
        .world_id = "asset/map_asset/map_files/battle_desert.json",
        .file = "asset/battlebg/desert_battle.png",
        .rect = { 0, 0, 1920, 1080 },
        .size = { 1, 1 }
    },
    {
        .world_id = "asset/map_asset/map_files/forest_map.json",
        .file = "asset/battlebg/forest.png",
        .rect = { -20, 0, 1920, 1080 },
        .size = { 1.2, 1.2 }
    },
    {
        .world_id = "asset/map_asset/map_files/volcano.json",
        .file = "asset/battlebg/volcano.png",
        .rect = { 0, 500, 1920, 1080 },
        .size = { 0.5, 0.5 }
    },
    {
        .world_id = "asset/map_asset/map_files/inside_castle.json",
        .file = "asset/battlebg/castle.png",
        .rect = { 0, 20, 1920, 1080 },
        .size = { 1, 1 }
    }
};

int create_battle(game_t *game, battlemanager_t *battlemanager)
{
    game_state_t *state = game->state;
    sfTexture *texture;
    sfIntRect rect;

    for (size_t i = 0; i < ARRAY_SIZE(BATTLE_BG); i++) {
        rect = BATTLE_BG[i].rect;
        if (estrcmp(state->save.map_id, BATTLE_BG[i].world_id) != 0)
            continue;
        texture = create_texture(game, BATTLE_BG[i].file, &rect);
        battlemanager->background = create_sprite(texture, NULL);
        sfSprite_setScale(battlemanager->background, BATTLE_BG[i].size);
        break;
    }
    battlemanager->attack_clock = create_pausable_clock(game);
    if (!create_attack_fx(game, battlemanager))
        return (-1);
    D_ASSERT(battlemanager->attack_clock, NULL, "Can't create battle clock", -1)
    return (0);
}

static battle_opponent_t *get_first_enemy(battlemanager_t *battlemanager)
{
    battle_opponent_t *alive_opponents[10];
    int j = 0;

    for (int i = 0; i < battlemanager->enemies_count; i++) {
        if (battlemanager->enemies[i].health > 0)
            alive_opponents[j++] = &battlemanager->enemies[i];
    }
    if (j == 0)
        return (NULL);
    return (alive_opponents[rand() % j]);
}

static void update_attack(game_t *game, battlemanager_t *battlemanager,
    battle_opponent_t *player, battle_opponent_t *enemy)
{
    int spell_id = battlemanager->hud->selected_spell_id;

    if (battlemanager->is_player_turn) {
        if (battlemanager->hud->selected_spell_id != -1) {
            battlemanager->source = player;
            battlemanager->target = enemy;
            battlemanager->spell = &player->spells[spell_id];
            start_attack(game, battlemanager);
            battlemanager->hud->selected_spell_id = -1;
            battlemanager->is_player_turn = false;
            battlemanager->attack_clock->time = 0;
        }
    } else {
        battlemanager->source = enemy;
        battlemanager->target = player;
        battlemanager->spell = &enemy->spells[rand() % count_spells(enemy)];
        start_attack(game, battlemanager);
        battlemanager->attack_clock->time = 0;
        battlemanager->is_player_turn = true;
    }
}

void update_battle(game_t *game UNUSED, battlemanager_t *battlemanager)
{
    battle_opponent_t *enemy = get_first_enemy(battlemanager);
    battle_opponent_t *player = &battlemanager->friends[0];

    if (battlemanager->attack_clock->time > 1.0f) {
        if (!is_attack_anim_in_progress(battlemanager)) {
            if (battlemanager->source!= NULL && battlemanager->target != NULL) {
                end_attack(game, battlemanager);
                battlemanager->attack_clock->time = 0;
                return;
            }
            if (enemy == NULL || player->health <= 0) {
                battlemanager->exit_code = (player->health <= 0) ? 0 : 1;
                switch_to_scene(game, -1);
                return;
            }
            update_attack(game, battlemanager, player, enemy);
        }
    }
    tick_pausable_clock(battlemanager->attack_clock);
}

void destroy_battle(game_t *game UNUSED, battlemanager_t *battlemanager)
{
    game_state_t *state = game->state;
    battle_opponent_t *player = &battlemanager->friends[0];

    state->save.player_hp = player->health;
    state->save.player_lv = player->level;
    destroy_attack_fx(game, battlemanager);
    destroy_pausable_clock(battlemanager->attack_clock);
    sfSprite_destroy(battlemanager->background);
}