/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estr_isupper
*/

#include <erty/ectypes.h>

bool estr_isupper(const_cstr_t str)
{
    for (size_t i = 0; str[i]; i++)
        if (!eis_upper(str[i]))
            return (false);
    return (true);
}
