/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estr_isalpha
*/

#include <erty/ectypes.h>

bool estr_isalpha(const_cstr_t str)
{
    for (size_t i = 0; str[i]; i++)
        if (!eis_alpha(str[i]))
            return (false);
    return (true);
}