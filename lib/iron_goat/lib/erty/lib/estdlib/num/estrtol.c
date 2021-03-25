/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estrtol
*/

#include <erty/ectypes.h>
#include <erty/estdlib.h>

long estrtol(cstr_t str, cstr_t *endptr, i32_t base)
{
    long result = 0;
    size_t i = 0;
    i8_t sign = eget_start_sign(str, &i);
    u8_t indexbase = 0;

    *endptr = str;
    if (sign == -1)
        (*endptr)++;
    while (eis_valid_strtoll(**endptr, base, &indexbase)) {
        if (ADD_OVERFLOW_CHECK(result, indexbase + 1))
            return (0);
        result += indexbase + 1;
        if (eis_valid_strtoll(*(*endptr + 1), base, &indexbase)) {
            if (MUL_OVERFLOW_CHECK(result, base))
                return (0);
            result *= base;
        }
        (*endptr)++;
    }
    return (MUL_OVERFLOW_CHECK(result, sign) ? 0 : result * sign);
}