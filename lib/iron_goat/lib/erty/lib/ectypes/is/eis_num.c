/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eis_num
*/

#include <erty/ectypes.h>

bool eis_num(const i32_t c)
{
    return (c >= '0' && c <= '9');
}