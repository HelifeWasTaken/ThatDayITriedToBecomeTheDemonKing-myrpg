/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estr_isprintable
*/

#include <erty/ectypes.h>

bool estr_isprintable(const_cstr_t str)
{
    for (size_t i = 0; str[i]; i++)
        if (!eis_printable(str[i]))
            return (false);
    return (true);
}
