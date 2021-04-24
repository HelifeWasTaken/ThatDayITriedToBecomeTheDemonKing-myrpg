/*
** EPITECH PROJECT, 2021
** set_animable_animation
** File description:
** Source code
*/

#include "distract/animable.h"

void set_animable_animation(animable_t *animable, int id)
{
    animable->current_anim = id;
    set_animable_frame(animable, 0);
}