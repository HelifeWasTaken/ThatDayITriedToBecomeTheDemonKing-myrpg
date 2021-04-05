/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** print
*/

#include <erty/string/esstring.h>
#include <erty/estdio.h>

ssize_t print_sstr(const string_t *this)
{
    return (eputs(this->str));
}