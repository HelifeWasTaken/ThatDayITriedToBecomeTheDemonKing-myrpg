/*
** EPITECH PROJECT, 2021
** friends
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/graphics.h"
#include "distract/resources.h"
#include "erty/estdlib.h"
#include "erty/string/ecstring.h"
#include "myrpg/asset.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include <stdlib.h>

static const animable_info_t PLAYER_ANIMABLE_INFO = {
    .animations = {
        { 4, 6 },   // BAT_ANIM_IDLE
        { 0, 3 },   // BAT_ANIM_ATTACK
        { 11, 11 }, // BAT_ANIM_DEATH
        { 12, 12 }, // BAT_ANIM_ITEM
        {},         // placeholder
        {},         // placeholder
        {},         // placeholder
        {},         // placeholder
        { 7, 9 },   // BAT_ANIM_SPELL_1
        {},         // BAT_ANIM_SPELL_2
        {}          // BAT_ANIM_SPELL_3
    },
    .frame_size = { 90, 83 },
    .frames_per_line = 7
};

static const battle_spell_t PLAYER_SPELLS[] = {
    {
        .name = "Attack",
        .mana = 0,
        .efficiency = 5,
        .type = BST_NOT_A_SPELL,
        .anim = BAT_ANIM_ATTACK,
        .attack_fx_file = "asset/fx/classic_hit.png",
        .attack_fx_frames_per_line = 5,
        .attack_fx_frames_count = 10
    },
    {
        .name = "Charm",
        .mana = 1,
        .efficiency = 30,
        .type = BST_AIR,
        .anim = BAT_ANIM_SPELL_1,
        .attack_fx_file = "asset/fx/classic_hit.png",
        .attack_fx_frames_per_line = 5,
        .attack_fx_frames_count = 10
    }
};

static void fill_player_state(game_t *game, battlemanager_t *manager)
{
    game_state_t *state = game->state;

    manager->friends[0].name = "Bard";
    manager->friends[0].asset_file = HERO_FIGHT_PATH;
    manager->friends[0].asset_rect = FULL_HERO_FIGHT_RECT;
    manager->friends[0].scale = HERO_SCALE;
    manager->friends[0].animable_info = PLAYER_ANIMABLE_INFO;
    manager->friends[0].health = state->save.player_hp +
        (5 + state->save.player_lv);
    manager->friends[0].level = state->save.player_lv;
    manager->friends[0].max_mana = 100;
    ememcpy(manager->friends[0].spells, PLAYER_SPELLS, sizeof(PLAYER_SPELLS));
    manager->friends[0].spells[0].efficiency += (state->save.player_lv + 2);
}

static int create_friend(game_t *game, battle_opponent_t *friend)
{
    sfTexture *texture;

    texture = create_texture(game, friend->asset_file, &friend->asset_rect);
    D_ASSERT(texture, NULL, "Cannot create texture", -1)
    friend->animable_info.sprite = create_sprite(texture, NULL);
    D_ASSERT(friend->animable_info.sprite, NULL, "Cannot create sprite", -1)
    friend->animable = (animable_t) {0};
    set_animable_info(&friend->animable, &friend->animable_info);
    set_animable_animation(&friend->animable, 0);
    sfSprite_scale(friend->animable_info.sprite, friend->scale);
    for (int i = 0; friend->spells[i].attack_fx_file != NULL; i++) {
        friend->spells[i].attack_fx_texture = create_texture(game,
            friend->spells[i].attack_fx_file, NULL);
        D_ASSERT(friend->spells[i].attack_fx_file, NULL, "Can't create attack"
            " fx", false);
    }
    return (0);
}

int create_battlemanager_friends(game_t *game, battlemanager_t *manager)
{
    fill_player_state(game, manager);
    if (create_friend(game, &manager->friends[0]) < 0)
        return (-1);
    manager->friends_count++;
    manager->friends[0].pos = VEC2F(470, 150);
    sfSprite_setPosition(manager->friends[0].animable_info.sprite,
        VEC2F(450, 130));
    return (0);
}