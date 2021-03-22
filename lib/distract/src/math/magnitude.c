/*
** EPITECH PROJECT, 2020
** magnitude
** File description:
** Source code
*/
#include "SFML/Graphics.h"
#include "distract/math.h"
#include "math.h"

float v2fmagnitude(sfVector2f *vector)
{
    return (sqrt(vector->x * vector->x + vector->y * vector->y));
}

float v2imagnitude(sfVector2i *vector)
{
    return (sqrt(vector->x * vector->x + vector->y * vector->y));
}