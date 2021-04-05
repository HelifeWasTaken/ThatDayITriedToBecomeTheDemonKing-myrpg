/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eftoa
*/

#include <erty/string/ecstring.h>
#include <erty/estdlib.h>

cstr_t eftoa(f64_t nb, u8_t precision, cstr_t tofill, const_cstr_t base)
{
    i64_t decimals = eget_float_decimals(nb, precision);
    i64_t rounded = (i64_t)nb;
    size_t tmpsize = 0;

    eitoa(rounded, tofill, base);
    tmpsize = estrlen(tofill);
    tofill[tmpsize] = '.';
    eitoa(decimals, tofill + tmpsize + 1, base);
    return (tofill);
}
