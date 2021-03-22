/*
** EPITECH PROJECT, 2020
** math
** File description:
** Source code
*/

#ifndef DISTRACT_MATH_H
#define DISTRACT_MATH_H
#include "SFML/Graphics.h"

float lerp(float a, float b, float t);

sfVector2f v2flerp(sfVector2f *v1, sfVector2f *v2, float t);

sfVector2i v2ilerp(sfVector2i *v1, sfVector2i *v2, float t);

float v2fmagnitude(sfVector2f *vector);

float v2imagnitude(sfVector2i *vector);

sfVector2f v2fnormalized(sfVector2f *vector);

sfVector2i v2inormalized(sfVector2i *vector);

float v2fdistance(sfVector2f *v1, sfVector2f *v2);

float v2idistance(sfVector2i *v1, sfVector2i *v2);

sfVector2f *v2fadd(sfVector2f *v1, sfVector2f *v2);

sfVector2i *v2iadd(sfVector2i *v1, sfVector2i *v2);

sfVector2f *v2fsub(sfVector2f *v1, sfVector2f *v2);

sfVector2i *v2isub(sfVector2i *v1, sfVector2i *v2);

sfVector2f *v2fmulf(sfVector2f *v1, float f);

sfVector2i *v2imulf(sfVector2i *v1, float f);

#define ABS(x) (x < 0 ? -x : x)

#endif //DISTRACT_MATH_H