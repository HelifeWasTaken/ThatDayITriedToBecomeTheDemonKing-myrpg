/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eis_alphanum
*/

#include <erty/ectypes.h>

bool eis_alphanum(const i32_t c)
{
    return (eis_alpha(c) || eis_num(c));
}