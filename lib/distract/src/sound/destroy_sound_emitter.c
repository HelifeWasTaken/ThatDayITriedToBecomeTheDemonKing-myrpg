/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** destroy_sound_emitter.c
*/

#include "distract/sound.h"

void destroy_sound_emitter(sound_emitter_t *emitter)
{
    free(emitter);
}