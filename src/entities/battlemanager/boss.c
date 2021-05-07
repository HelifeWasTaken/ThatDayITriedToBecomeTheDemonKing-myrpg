/*
** EPITECH PROJECT, 2021
** entities
** File description:
** Source code
*/

#include "distract/animable.h"
#include "distract/debug.h"
#include "distract/math.h"
#include "myrpg/battle.h"
#undef ABS
#include "distract/graphics.h"
#include "distract/resources.h"
#include "erty/estdlib.h"
#include "erty/string/ecstring.h"
#include "myrpg/asset.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

static const battle_opponent_t BOSSES[] = {
    {
        .name = "Demon Boss",
        .asset_file = "asset/enemies/boss/demon.png",
        .asset_rect = { 0, 0, 3000, 3600 },
        .level = 1,
        .health = 300,
        .mana = 10,
        .max_mana = 10,
        .scale = { 1, 1 },
        .pos_offset = { 0, -100 },
        .animable_info = {
            .animations = {
                { 0, 4 },
                { 5, 14 },
                { 0, 0 }
            },
            .frame_size = { 3000 / 5, 3600 / 6 },
            .frames_per_line = 5
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 68,
                .type = BST_ROCK,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/fire_attack_boss.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 10,
                .attack_fx_size = { 3, 3 }
            }
        }
    },
    {
        .name = "Forest Lion",
        .asset_file = "asset/enemies/boss/forest_lion.png",
        .asset_rect = { 0, 0, 1000, 2400 },
        .level = 1,
        .health = 300,
        .mana = 10,
        .max_mana = 10,
        .scale = { 1, 1 },
        .pos_offset = { 0, 0 },
        .animable_info = {
            .animations = {
                { 0, 24 },
                { 25, 55 },
                { 0, 0 }
            },
            .frame_size = { 1000 / 5, 2400 / 12 },
            .frames_per_line = 5
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 68,
                .type = BST_ROCK,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/boss_natural_hit.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 20,
                .attack_fx_size = { 3, 3 }
            }
        }
    },
    {
        .name = "Troll King",
        .asset_file = "asset/enemies/boss/troll_king.png",
        .asset_rect = { 0, 0, 3600, 7920 },
        .level = 1,
        .health = 300,
        .mana = 10,
        .max_mana = 10,
        .scale = { 0.9, 0.9 },
        .pos_offset = { 0, -100 },
        .animable_info = {
            .animations = {
                { 0, 4 },
                { 5, 50 },
                { 0, 0 }
            },
            .frame_size = { 3600 / 5, 7920 / 11 },
            .frames_per_line = 5
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 68,
                .type = BST_ROCK,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/sand_boss.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 20,
                .attack_fx_size = { 3, 3 }
            }
        },
    },
    {
        .name = "Demon King",
        .asset_file = "asset/enemies/boss/final_boss.png",
        .asset_rect = { 0, 0, 2500, 4500 },
        .level = 1,
        .health = 15,
        .mana = 10,
        .max_mana = 10,
        .scale = { 0.5, 0.5 },
        .pos_offset = { 0, -50 },
        .animable_info = {
            .animations = {
                { 0, 9 },
                { 10, 41 },
                { 0, 0 }
            },
            .frame_size = { 2500 / 5, 4500 / 9 },
            .frames_per_line = 5
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 20,
                .type = BST_ROCK,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/classic_hit.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 10,
                .attack_fx_size = { 3, 3 }
            }
        }
    }
};

int create_battlemanager_boss(game_t *game, battlemanager_t *manager)
{
    game_state_t *state = game->state;
    int bosses_count = ARRAY_SIZE(BOSSES);

    if (state->last_boss_id < 0 || state->last_boss_id >= bosses_count)
        return (-1);
    manager->enemies_count = 1;
    create_battle_enemy(game, &manager->enemies[0],
        &BOSSES[state->last_boss_id]);
    place_battle_enemies(manager, manager->enemies_count);
    return (0);
}