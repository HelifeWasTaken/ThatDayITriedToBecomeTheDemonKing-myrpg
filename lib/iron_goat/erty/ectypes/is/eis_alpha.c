/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eis_alpha
*/

#include <erty/ectypes.h>

bool eis_alpha(const i32_t c)
{
    return (eis_lower(c) || eis_upper(c));
}