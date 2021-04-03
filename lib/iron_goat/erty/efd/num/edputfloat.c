/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** edputfloat
*/

#include <erty/efd.h>
#include <erty/estdlib.h>

static size_t edputfloat_print(i32_t fd, int64_t nb, uint8_t precision)
{
    return ((precision) ?
        edputfloat_print(fd, nb / 10, --precision) +
        edputchar(fd, nb % 10 + '0') : 0);
}

size_t edputfloat(i32_t fd, f64_t nb, uint8_t precision)
{
    return ((precision) ?
        edputnbr(fd, (int64_t)nb) + edputchar(fd, '.') +
        edputfloat_print(fd,
            eget_float_decimals(ABS(nb), precision), precision) :
        edputnbr(fd, (int64_t)nb));
}
