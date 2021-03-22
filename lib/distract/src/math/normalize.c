/*
** EPITECH PROJECT, 2020
** normalize
** File description:
** Source code
*/
#include "SFML/Graphics.h"
#include "distract/math.h"
#include "math.h"

sfVector2f v2fnormalized(sfVector2f *vector)
{
    float magnitude = v2fmagnitude(vector);
    sfVector2f vec;

    if (magnitude < 0.05)
        return (sfVector2f) { 0, 0 };
    vec.x = vector->x / magnitude;
    vec.y = vector->y / magnitude;
    return (vec);
}

sfVector2i v2inormalized(sfVector2i *vector)
{
    float magnitude = v2imagnitude(vector);
    sfVector2i vec;

    if (magnitude < 0.05)
        return (sfVector2i) { 0, 0 };
    vec.x = vector->x / magnitude;
    vec.y = vector->y / magnitude;
    return (vec);
}