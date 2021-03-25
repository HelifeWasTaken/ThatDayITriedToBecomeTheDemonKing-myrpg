/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estrchr
*/

#include <erty/ectypes.h>

cstr_t estrchr(const_cstr_t str, i32_t c)
{
    for (size_t i = 0; str[i]; i++)
        if (str[i] == c)
            return ((char *)&str[i]);
    return (NULL);
}