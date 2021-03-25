/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eduputnbr
*/

#include <erty/efd.h>

size_t efuputnbr(FILE *stream, u64_t nb)
{
    return (eduputnbr(stream->_fileno, nb));
}