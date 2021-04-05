/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** egetsubstr
*/

#include <erty/string/ecstring.h>
#include <erty/estdlib.h>

cstr_t egetsubstr(const_cstr_t str, i64_t start, i64_t end)
{
    int64_t len = estrlen(str);

    if (start > len)
        return (NULL);
    if (start < 0) {
        if (ABS(start) > len)
            return (NULL);
        else
            start = len + start;
    }
    if (end > len || start >= end)
        return (NULL);
    return (estrndup(str + start, end - start));
}