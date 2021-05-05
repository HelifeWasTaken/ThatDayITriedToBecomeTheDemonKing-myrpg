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

static const battle_opponent_t ENEMIES[] = {
    {
        .name = "Skeleton",
        .asset_file = "asset/enemies/skeleton.png",
        .asset_rect = { 0, 0, 1144, 452 },
        .level = 1,
        .health = 70,
        .mana = 10,
        .max_mana = 10,
        .scale = { 1, 1 },
        .animable_info = {
            .animations = {
                { 0, 3 },
                { 7, 13 },
                { 14, 17 }
            },
            .frame_size = { 150, 150 },
            .frames_per_line = 7
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 18,
                .type = BST_NOT_A_SPELL,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/classic_hit.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 10
            },
            {
                .name = "Dark Attack",
                .mana = 0,
                .efficiency = 28,
                .type = BST_NOT_A_SPELL,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/dark_attack.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 10
            }
        }
    },
    {
        .name = "Goblin",
        .asset_file = "asset/enemies/goblin.png",
        .asset_rect = { 0, 0, 1200, 450 },
        .level = 1,
        .health = 40,
        .mana = 10,
        .max_mana = 10,
        .scale = { 1, 1 },
        .animable_info = {
            .animations = {
                { 8, 11 },
                { 0, 7 },
                { 14, 17 }
            },
            .frame_size = { 150, 150 },
            .frames_per_line = 8
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 15,
                .type = BST_NOT_A_SPELL,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/classic_hit.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 10
            }
        }
    },
    {
        .name = "Devil Eye",
        .asset_file = "asset/enemies/devil_eye.png",
        .asset_rect = { 0, 0, 1200, 450 },
        .level = 1,
        .health = 20,
        .mana = 10,
        .max_mana = 10,
        .scale = { 1, 1 },
        .animable_info = {
            .animations = {
                { 8, 13 },
                { 0, 7 },
                { 14, 17 }
            },
            .frame_size = { 150, 150 },
            .frames_per_line = 8
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 8,
                .type = BST_NOT_A_SPELL,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/fangs_attack.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 20
            }
        }
    },
    {
        .name = "Mushroo",
        .asset_file = "asset/enemies/mushroo.png",
        .asset_rect = { 0, 0, 1200, 450 },
        .level = 1,
        .health = 50,
        .mana = 10,
        .max_mana = 10,
        .scale = { 1, 1 },
        .animable_info = {
            .animations = {
                { 8, 11 },
                { 0, 7 },
                { 14, 17 }
            },
            .frame_size = { 150, 150 },
            .frames_per_line = 8
        },
        .spells = {
            {
                .name = "Attack",
                .mana = 0,
                .efficiency = 10,
                .type = BST_NOT_A_SPELL,
                .anim = BAT_ANIM_ATTACK,
                .attack_fx_file = "asset/fx/mushroom_atk.png",
                .attack_fx_frames_per_line = 5,
                .attack_fx_frames_count = 20
            }
        }
    }
};

static const sfVector2f ENEMIES_POSITIONS[][3] = {
    { {150, 120 + 30} },
    { {150, 80 + 30}, {170, 150 + 30} },
    { {150, 70 + 30}, {170, 120 + 30}, {150, 160 + 30} }
};

static const battle_opponent_t *select_rand_enemy(int level)
{
    const battle_opponent_t *rand_opponent;

    do {
        rand_opponent = &ENEMIES[rand() % (ARRAY_SIZE(ENEMIES))];
    } while ((rand_opponent->level / 10) > (level / 10));
    return (rand_opponent);
}

int count_spells(battle_opponent_t *enemy)
{
    int spell_count = 0;

    for (int i = 0; enemy->spells[i].name != NULL; i++)
        spell_count++;
    return (spell_count);
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
    for (int i = 0; enemy->spells[i].attack_fx_file != NULL; i++) {
        enemy->spells[i].attack_fx_texture = create_texture(game,
            enemy->spells[i].attack_fx_file, NULL);
        D_ASSERT(enemy->spells[i].attack_fx_file, NULL, "Can't create attack"
            " fx", false);
    }
    enemy->animable = (animable_t) {0};
    set_animable_info(&enemy->animable, &enemy->animable_info);
    set_animable_animation(&enemy->animable, 0);
    sfSprite_scale(enemy->animable_info.sprite, enemy->scale);
    return (0);
}

static void place_enemies(battlemanager_t *manager, int entity_count)
{
    sfVector2f pos;
    sfFloatRect bounds;
    sfSprite *sprite;

    for (int i = 0; i < entity_count; i++) {
        sprite = manager->enemies[i].animable_info.sprite;
        pos = ENEMIES_POSITIONS[entity_count - 1][i];
        bounds = sfSprite_getGlobalBounds(sprite);
        manager->enemies[i].pos = pos;
        sfSprite_setPosition(sprite,
            v2fsub(pos, VEC2F(bounds.width / 2, bounds.height / 2)));
    }
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
    place_enemies(manager, entity_count);
    return (0);
}