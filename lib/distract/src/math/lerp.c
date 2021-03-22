/*
** EPITECH PROJECT, 2020
** lerp
** File description:
** Source code
*/
#include "SFML/Graphics.h"

float lerp(float a, float b, float t)
{
    return (1 - t) * a + t * b;
}

sfVector2f v2flerp(sfVector2f *v1, sfVector2f *v2, float t)
{
    sfVector2f vec;

    vec.x = lerp(v1->x, v2->x, t);
    vec.y = lerp(v1->y, v2->y, t);
    return (vec);
}

sfVector2i v2ilerp(sfVector2i *v1, sfVector2i *v2, float t)
{
    sfVector2i vec;

    vec.x = (int) lerp((float) v1->x, (float) v2->x, t);
    vec.y = (int) lerp((float) v1->y, (float) v2->y, t);
    return (vec);
}