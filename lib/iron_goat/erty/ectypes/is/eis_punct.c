/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eis_punct
*/

#include <erty/ectypes.h>

bool eis_punct(const i32_t c)
{
    return ((c >= 33 && c <= 64) ||
        (c >= 91 && c <= 96) ||
        (c >= 123 && c <= 126));
}