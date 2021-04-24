/*
** EPITECH PROJECT, 2021
** set_animable_info
** File description:
** Source code
*/

#include "distract/animable.h"

void set_animable_info(animable_t *animable, animable_info_t *info)
{
    animable->info = *info;
    set_animable_animation(animable, 0);
}