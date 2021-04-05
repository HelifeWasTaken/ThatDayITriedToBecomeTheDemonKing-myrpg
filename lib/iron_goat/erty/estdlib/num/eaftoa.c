/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eaftoa
*/

#include <erty/string/ecstring.h>
#include <erty/estdlib.h>

cstr_t eaftoa(f64_t nb, u8_t precision, const_cstr_t base)
{
    i64_t rounded = (i64_t)nb;
    i64_t decimals = eget_float_decimals(nb, precision);
    size_t basesize = estrlen(base);
    cstr_t new = emalloc(sizeof(char) *
        (enb_baselen(rounded, basesize) + enb_baselen(decimals, basesize) + 2));
    size_t tmpsize = 0;

    if (new != NULL) {
        eitoa(rounded, new, base);
        tmpsize = estrlen(new);
        new[tmpsize] = '.';
        eitoa(decimals, new + tmpsize + 1, base);
    } else {
        ASSERT("Erty", "Eaftoa memory allocation failed");
    }
    return (new);
}
