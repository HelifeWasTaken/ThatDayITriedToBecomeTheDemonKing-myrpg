/*
** EPITECH PROJECT, 2020
** magnitude
** File description:
** Source code
*/
#include "SFML/Graphics.h"
#include "distract/math.h"

sfVector2f *pv2fadd(sfVector2f *v1, sfVector2f *v2)
{
    v1->x += v2->x;
    v1->y += v2->y;
    return (v1);
}

sfVector2i *pv2iadd(sfVector2i *v1, sfVector2i *v2)
{
    v1->x += v2->x;
    v1->y += v2->y;
    return (v1);
}

sfVector2f v2fadd(sfVector2f v1, sfVector2f v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    return (v1);
}

sfVector2i v2iadd(sfVector2i v1, sfVector2i v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    return (v1);
}