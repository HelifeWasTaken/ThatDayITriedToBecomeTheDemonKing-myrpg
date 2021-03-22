/*
** EPITECH PROJECT, 2020
** magnitude
** File description:
** Source code
*/
#include "SFML/Graphics.h"
#include "distract/math.h"

float v2fdistance(sfVector2f *v1, sfVector2f *v2)
{
    sfVector2f vec = { v2->x - v1->x, v2->y - v1->y };

    return (v2fmagnitude(&vec));
}

float v2idistance(sfVector2i *v1, sfVector2i *v2)
{
    sfVector2i vec = { v2->x - v1->x, v2->y - v1->y };

    return (ABS(v2imagnitude(&vec)));
}