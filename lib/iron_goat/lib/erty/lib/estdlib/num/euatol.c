/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** euatol
*/

#include <erty/estdlib.h>

OPT(u64) euatol(const_cstr_t str)
{
    u64_t result = 0;
    size_t i = 0;

    while (eis_num(str[i])) {
        if (ADD_OVERFLOW_CHECK(result, (u64_t)(str[i] - '0')))
            return (ERR(u64));
        result += str[i] - '0';
        if (eis_num(str[i + 1])) {
            if (MUL_OVERFLOW_CHECK(result, (u64_t)10))
                return (ERR(u64));
            result *= 10;
        }
        i++;
    }
    return (OK(u64, result));
}