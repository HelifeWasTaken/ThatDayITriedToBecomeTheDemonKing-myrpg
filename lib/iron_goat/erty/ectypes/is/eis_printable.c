/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eis_printable
*/

#include <erty/ectypes.h>

bool eis_printable(const i32_t c)
{
    return (c >= 32 && c <= 126);
}