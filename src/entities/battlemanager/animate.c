/*
** EPITECH PROJECT, 2021
** animate
** File description:
** Source code
*/

#include "distract/animable.h"
#include "myrpg/battle.h"
#include "myrpg/entities.h"

static void update_animation(battlemanager_t *manager,
    battle_opponent_t *opponent)
{
    animable_t *anim = &opponent->animable;

    if (is_animation_done(anim)) {
        if (get_animable_animation(anim) == BAT_ANIM_DEATH)
            return;
        if (opponent->health > 0 || is_attack_anim_in_progress(manager))
            set_animable_animation(anim, BAT_ANIM_IDLE);
        else
            set_animable_animation(anim, BAT_ANIM_DEATH);
    } else {
        set_animable_frame(anim, get_animable_frame(anim) + 1);
    }
}

void animate_battlemanager_sprites(battlemanager_t *battlemanager)
{
    for (int i = 0; i < battlemanager->enemies_count; i++) {
        update_animation(battlemanager, &battlemanager->enemies[i]);
    }
    for (int i = 0; i < battlemanager->friends_count; i++) {
        update_animation(battlemanager, &battlemanager->friends[i]);
    }
}