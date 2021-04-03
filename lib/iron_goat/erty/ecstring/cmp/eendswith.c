/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eendswith
*/

#include <erty/string/ecstring.h>

bool eendswith(const_cstr_t haystack, const_cstr_t needle)
{
    size_t sizehaystack = estrlen(haystack);
    size_t sizeneedle = estrlen(needle);

    if (sizehaystack < sizeneedle)
        return (false);
    return (estrcmp(haystack + sizehaystack - sizeneedle, needle) == 0);
}