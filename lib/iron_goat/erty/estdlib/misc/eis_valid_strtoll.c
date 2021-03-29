/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eis_valid_strtoll
*/

#include <erty/ectypes.h>

bool eis_valid_strtoll(i32_t c, i32_t basesize, u8_t *indexbase)
{
    cstr_t base = "0123456789abcdefghijklmnopqrstuvwxyz";

    for (*indexbase = 0; *indexbase < basesize; (*indexbase)++)
        if (c == base[*indexbase])
            return (true);
    return (false);
}