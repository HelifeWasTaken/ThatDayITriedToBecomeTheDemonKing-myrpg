/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estartswith
*/

#include <erty/string/ecstring.h>

bool estartswith(const_cstr_t haystack, const_cstr_t needle)
{
    return ((estrncmp(haystack, needle, estrlen(needle) == 0)));
}