/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estrlen
*/

#include <erty/ectypes.h>

size_t estrlen(const_cstr_t str)
{
    size_t i = 0;

    if (str)
        for (; str[i]; i++);
    return (i);
}