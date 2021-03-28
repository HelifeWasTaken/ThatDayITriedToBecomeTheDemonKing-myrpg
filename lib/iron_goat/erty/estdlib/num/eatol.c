/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eatol
*/

#include <erty/ectypes.h>
#include <erty/estdlib.h>

OPT(i64) eatol(const_cstr_t str)
{
    i64_t result = 0;
    size_t i = 0;
    i8_t sign = eget_start_sign(str, &i);

    while (eis_num(str[i])) {
        if (ADD_OVERFLOW_CHECK(result, (long long)(str[i] - '0')))
            return (ERR(i64));
        result += str[i] - '0';
        if (eis_num(str[i + 1])) {
            if (MUL_OVERFLOW_CHECK(result, (long long)10))
                return (ERR(i64));
            result *= 10;
        }
        i++;
    }
    return (MUL_OVERFLOW_CHECK(result, (long long)sign) ?
        ERR(i64) : OK(i64, result * (i64_t)sign));
}