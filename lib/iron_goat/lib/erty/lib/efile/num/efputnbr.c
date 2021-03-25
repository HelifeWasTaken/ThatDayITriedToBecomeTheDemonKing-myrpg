/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** edputnbr
*/

#include <erty/efd.h>

size_t efputnbr(FILE *stream, i64_t nb)
{
    return (edputnbr(stream->_fileno, nb));
}