/*
** EPITECH PROJECT, 2021
** set_animable_frame
** File description:
** Source code
*/

#include "distract/animable.h"
#include "distract/debug.h"
#include "distract/def.h"
#include <SFML/Graphics.h>
#include <stdio.h>

void set_animable_frame(animable_t *animable, int id)
{
    if (animable->info.frames_per_line == 0) {
        print_error("Animable have an invalid frames per line!");
        return;
    }
    animable->current_sheet_frame
        = animable->info.animations[animable->current_anim].start_id + id;
    sfSprite_setTextureRect(animable->info.sprite, IRECT(
        (animable->current_sheet_frame % animable->info.frames_per_line)
            * animable->info.frame_size.x,
        (animable->current_sheet_frame / animable->info.frames_per_line)
            * animable->info.frame_size.y,
        animable->info.frame_size.x, animable->info.frame_size.y));
    printf("%d %d\n", sfSprite_getTextureRect(animable->info.sprite).left, sfSprite_getTextureRect(animable->info.sprite).top);
}