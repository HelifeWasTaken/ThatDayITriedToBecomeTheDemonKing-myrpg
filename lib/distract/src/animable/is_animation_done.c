/*
** EPITECH PROJECT, 2021
** is_animation_done
** File description:
** Source code
*/

#include "distract/animable.h"

bool is_animation_done(animable_t *animable)
{
    return (animable->current_sheet_frame
        == animable->info.animations[animable->current_anim].end_id);
}