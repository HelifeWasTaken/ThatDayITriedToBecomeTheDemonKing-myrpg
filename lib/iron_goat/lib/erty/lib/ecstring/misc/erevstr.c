/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** erevstr
*/

#include <erty/string/ecstring.h>
#include <erty/estdlib.h>

cstr_t erevstr(cstr_t str)
{
    size_t size_str = estrlen(str);

    for (size_t i = 0; i < size_str / 2; i++)
        AUTO_SWAP(str[i], str[size_str - i - 1]);
    return (str);
}
