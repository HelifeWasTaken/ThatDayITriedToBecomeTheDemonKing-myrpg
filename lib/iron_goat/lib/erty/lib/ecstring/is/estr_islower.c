/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estr_islower
*/

#include <erty/ectypes.h>

bool estr_islower(const_cstr_t str)
{
    for (size_t i = 0; str[i]; i++)
        if (!eis_lower(str[i]))
            return (false);
    return (true);
}
