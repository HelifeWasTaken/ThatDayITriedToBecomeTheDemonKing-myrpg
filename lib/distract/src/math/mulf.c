/*
** EPITECH PROJECT, 2020
** mulf
** File description:
** Source code
*/
#include "SFML/Graphics.h"
#include "distract/math.h"

sfVector2f v2fmulf(sfVector2f v1, float f)
{
    v1.x *= f;
    v1.y *= f;
    return (v1);
}

sfVector2i v2imulf(sfVector2i v1, float f)
{
    v1.x *= f;
    v1.y *= f;
    return (v1);
}

sfVector2f *pv2fmulf(sfVector2f *v1, float f)
{
    v1->x *= f;
    v1->y *= f;
    return (v1);
}

sfVector2i *pv2imulf(sfVector2i *v1, float f)
{
    v1->x *= f;
    v1->y *= f;
    return (v1);
}