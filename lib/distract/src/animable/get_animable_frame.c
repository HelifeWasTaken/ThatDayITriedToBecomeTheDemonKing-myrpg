/*
** EPITECH PROJECT, 2021
** set_animable_frame
** File description:
** Source code
*/

#include "distract/animable.h"

int get_animable_frame(animable_t *animable)
{
    return (animable->current_sheet_frame
        - animable->info.animations[animable->current_anim].start_id);
}