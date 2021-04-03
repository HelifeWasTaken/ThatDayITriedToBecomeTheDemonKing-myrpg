/*
** EPITECH PROJECT, 2021
** matrix
** File description:
** matri
*/

#ifndef MATRIX_H_
#define MATRIX_H_

#include <SFML/Graphics.h>
#include <math.h>

static inline void matrix_set_shear(
    float *matrix, sfVector2f *sh)
{
    matrix[0] = 1;
    matrix[1] = sh->x;
    matrix[2] = 0;
    matrix[3] = sh->y;
    matrix[4] = 1;
    matrix[5] = 0;
    matrix[6] = 0;
    matrix[7] = 0;
    matrix[8] = 1;
}

static inline void matrix_set_translation(
    float *matrix, sfVector2f *ts)
{
    matrix[0] = 1;
    matrix[1] = 0;
    matrix[2] = 0;
    matrix[3] = 0;
    matrix[4] = 1;
    matrix[5] = 0;
    matrix[6] = ts->x;
    matrix[7] = ts->y;
    matrix[8] = 1;
}

static inline void matrix_set_rotation(
    float *matrix, float rot)
{
    matrix[0] = cos(rot);
    matrix[1] = sin(rot);
    matrix[2] = 0;
    matrix[3] = -sin(rot);
    matrix[4] = cos(rot);
    matrix[5] = 0;
    matrix[6] = 0;
    matrix[7] = 0;
    matrix[8] = 1;
}

static inline void matrix_set_scale(
    float *matrix, sfVector2f *sc)
{
    matrix[0] = sc->x;
    matrix[1] = 0;
    matrix[2] = 0;
    matrix[3] = 0;
    matrix[4] = sc->y;
    matrix[5] = 0;
    matrix[6] = 0;
    matrix[7] = 0;
    matrix[8] = 1;
}

static inline void matrix_compute(float *matrix, float *matrix2)
{
    for (int i = 0; i < 9; i++)
        matrix[i] = matrix[i] + matrix2[i];
}

#endif