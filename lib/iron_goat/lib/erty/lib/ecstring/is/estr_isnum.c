/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estr_isnum
*/

#include <erty/ectypes.h>

bool estr_isnum(const_cstr_t str)
{
    for (size_t i = 0; str[i]; i++)
        if (!eis_num(str[i]))
            return (false);
    return (true);
}