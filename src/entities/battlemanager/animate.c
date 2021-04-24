/*
** EPITECH PROJECT, 2021
** animate
** File description:
** Source code
*/

#include "distract/animable.h"
#include "myrpg/entities.h"


void animate_battlemanager_sprites(battlemanager_t *battlemanager)
{
    animable_t *anim;

    for (int i = 0; i < battlemanager->enemies_count; i++) {
        anim = &battlemanager->enemies[i].animable;
        if (is_animation_done(anim)) {
            set_animable_animation(anim, 2);
        } else {
            set_animable_frame(anim, get_animable_frame(anim) + 1);
        }
    }
    for (int i = 0; i < battlemanager->friends_count; i++) {
        anim = &battlemanager->friends[i].animable;
        if (is_animation_done(anim)) {
            set_animable_animation(anim, 2);
        } else {
            set_animable_frame(anim, get_animable_frame(anim) + 1);
        }
    }
}