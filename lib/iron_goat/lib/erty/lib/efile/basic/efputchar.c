/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** efputchar
*/

#include <erty/ewrite.h>
#include <erty/ectypes.h>

ssize_t efputchar(FILE *stream, i32_t c)
{
    return (efwrite(stream, &c, 1));
}
