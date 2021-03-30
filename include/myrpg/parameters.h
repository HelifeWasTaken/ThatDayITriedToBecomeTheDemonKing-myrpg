/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** parameters
*/

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "distract/entity.h"
#include "myrpg/game.h"
#include "define.h"

typedef struct parameters
{
    float music_vol;
    float vfx_vol;
    float voice_vol;
    bool music_muted;
    bool vfx_muted;
    bool voice_muted;
} parameters_t;

#endif /* !PARAMETERS_H_ */
