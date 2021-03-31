/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** e_errputchar
*/

#include <erty/efile.h>

ssize_t e_errputchar(i32_t c)
{
    return (efputchar(stderr, c));
}