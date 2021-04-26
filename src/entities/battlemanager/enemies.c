/*
** EPITECH PROJECT, 2021
** entities
** File description:
** Source code
*/

#include "distract/animable.h"
#include "distract/debug.h"
#include "distract/graphics.h"
#include "distract/resources.h"
#include "erty/estdlib.h"
#include "erty/string/ecstring.h"
#include "myrpg/asset.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>

static const battle_opponent_t ENEMIES[] = {
    {
        .name = "Bard but it's the bad one",
        .asset_file = "asset/hero/bard_combat.png",
        .asset_rect = { 0 ,0, 450, 166 },
        .level = 1,
        .health = 10,
        .mana = 10,
        .max_mana = 10,
        .scale = { 0.5, 0.5 },
        .animable_info = {
            .animations = {
                { 11, 13 }, // BAT_ANIM_IDLE
                { 0, 3 },   // BAT_ANIM_ATTACK
                { 8, 8 },   // BAT_ANIM_DEATH
                { 9, 9 },   // BAT_ANIM_ITEM
                {},         // placeholder
                {},         // placeholder
                {},         // placeholder
                {},         // placeholder
                { 5, 7 },   // BAT_ANIM_SPELL_1
                {},         // BAT_ANIM_SPELL_2
                {}          // BAT_ANIM_SPELL_3
            },
            .frame_size = { 90, 83 },
            .frames_per_line = 5
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 1,
                .type = BST_NOT_A_SPELL,
                .anim = BAT_ANIM_ATTACK,
            },
            {
                .name = "Charm",
                .mana = 10,
                .efficiency = 1,
                .type = BST_AIR,
                .anim = BAT_ANIM_SPELL_1,
            }
        }
    },
    {
        .name = "Skeleton",
        .asset_file = "asset/enemies/skeleton.png",
        .asset_rect = { 0, 0, 1144, 452 },
        .level = 1,
        .health = 10,
        .mana = 10,
        .max_mana = 10,
        .scale = { 1, 1 },
        .animable_info = {
            .animations = {
                { 0, 3 },   // BAT_ANIM_IDLE
                { 7, 13 },  // BAT_ANIM_ATTACK
                { 14, 17 }, // BAT_ANIM_DEATH,
                {},         // BAT_ANIM_ITEM
                {},         // placeholder
                {},         // placeholder
                {},         // placeholder
                {},         // placeholder
                {},         // BAT_ANIM_SPELL_1
                {},         // BAT_ANIM_SPELL_2
                {}          // BAT_ANIM_SPELL_3
                
            },
            .frame_size = { 150, 150 },
            .frames_per_line = 7
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 1,
                .type = BST_NOT_A_SPELL,
                .anim = BAT_ANIM_ATTACK,
            }
        }
    }
};

static const sfVector2f ENEMIES_POSITIONS[][3] = {
    { {150, 100} },
    { {150, 70}, {170, 120} },
    { {150, 70}, {170, 100}, {150, 120} }
};

static const battle_opponent_t *select_rand_enemy(int level)
{
    const battle_opponent_t *rand_opponent;

    do {
        rand_opponent = &ENEMIES[rand() % (ARRAY_SIZE(ENEMIES))];
    } while ((rand_opponent->level / 10) > (level / 10));
    return (rand_opponent);
}

static int create_enemy(game_t *game, battle_opponent_t *enemy, int level)
{
    sfTexture *texture;
    const battle_opponent_t *rand_enemy
        = select_rand_enemy(level);
    
    ememcpy(enemy, rand_enemy, sizeof(battle_opponent_t));
    texture = create_texture(game, enemy->asset_file, &enemy->asset_rect);
    D_ASSERT(texture, NULL, "Cannot create texture", -1)
    enemy->animable_info.sprite = create_sprite(texture, NULL);
    D_ASSERT(enemy->animable_info.sprite, NULL, "Cannot create sprite", -1)
    enemy->animable = (animable_t) {0};
    set_animable_info(&enemy->animable, &enemy->animable_info);
    set_animable_animation(&enemy->animable, 0);
    sfSprite_scale(enemy->animable_info.sprite, enemy->scale);
    return (0);
}

int create_battlemanager_enemies(game_t *game, battlemanager_t *manager)
{
    game_state_t *state = game->state;
    int entity_count = 1 + (rand() % 3);
    state->save.player_lv = 20;
    int level = state->save.player_lv / entity_count;

    if (level < 3) {
        level = 5;
        entity_count = 1;
    } else if (level < 10) {
        level = 5;
        entity_count = entity_count > 2 ? 2 : entity_count;
    }
    for (int i = 0; i < entity_count; i++) {
        if (create_enemy(game, &manager->enemies[i], level) == -1)
            return (-1);
        manager->enemies_count++;
    }
    for (int i = 0; i < entity_count; i++)
        sfSprite_setPosition(manager->enemies[i].animable_info.sprite,
            ENEMIES_POSITIONS[entity_count - 1][i]);
    return (0);
}