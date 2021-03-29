/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eget_float_decimals
*/

#include <erty/ectypes.h>

uint64_t eget_float_decimals(f64_t nb, u8_t precision)
{
    double rounded = (int64_t)nb;

    if (!precision)
        return (0);
    nb -= rounded;
    for (int8_t i = 0; i < precision; i++)
        nb *= 10.0f;
    return ((uint64_t)nb);
}