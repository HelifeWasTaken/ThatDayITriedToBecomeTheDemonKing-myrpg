/*
** EPITECH PROJECT, 2021
** friends
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/graphics.h"
#include "distract/resources.h"
#include "myrpg/asset.h"
#include "myrpg/entities.h"
#include "myrpg/state.h"
#include <stdlib.h>

static const animable_info_t PLAYER_ANIMABLE_INFO = {
    .animations = {
        { 0, 3 },
        { 11, 13 },
        { 5, 7 }
    },
    .frame_size = { 90, 83 },
    .frames_per_line = 5
};

static void fill_player_state(game_t *game, battlemanager_t *manager)
{
    game_state_t *state = game->state;

    manager->friends[0].name = "Bard";
    manager->friends[0].asset_file = HERO_FIGHT_PATH;
    manager->friends[0].scale = HERO_SCALE;
    manager->friends[0].animable_info = PLAYER_ANIMABLE_INFO;
    manager->friends[0].health = state->save.player_hp;
    manager->friends[0].level = state->save.player_lv;
    manager->friends[0].mana = state->save.player_mana;
    manager->friends[0].max_mana = 100;
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
    return (0);
}

int create_battlemanager_friends(game_t *game, battlemanager_t *manager)
{
    fill_player_state(game, manager);
    if (create_friend(game, &manager->friends[0]) < 0)
        return (-1);
    manager->friends_count++;
    sfSprite_setPosition(manager->friends[0].animable_info.sprite,
        VEC2F(450, 100));
    return (0);
}