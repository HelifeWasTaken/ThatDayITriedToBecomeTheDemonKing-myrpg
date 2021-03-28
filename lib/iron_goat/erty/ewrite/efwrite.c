/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** fewrite
*/

#include <erty/ewrite.h>

ssize_t efwrite(FILE *stream, void const *buf, size_t n)
{
    return (ewrite(stream->_fileno, buf, n));
}