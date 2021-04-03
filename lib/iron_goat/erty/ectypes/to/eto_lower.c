/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eto_lower
*/

#include <erty/ectypes.h>

i32_t eto_lower(i32_t c)
{
    return (eis_upper(c) ? c + 32 : c);
}