/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eputchar
*/

#include <erty/efile.h>

ssize_t eputchar(i32_t c)
{
    return (efputchar(stdout, c));
}