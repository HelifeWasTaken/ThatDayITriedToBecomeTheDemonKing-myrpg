/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** efputfloat
*/

#include <erty/efd.h>

size_t efputfloat(FILE *stream, f64_t nb, u8_t precision)
{
    return (edputfloat(stream->_fileno, nb, precision));
}