/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eto_upper
*/

#include <erty/ectypes.h>

i32_t eto_upper(i32_t c)
{
    return (eis_lower(c) ? c - 32 : c);
}