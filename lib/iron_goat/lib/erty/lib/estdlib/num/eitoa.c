/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eaitoa
*/

#include <erty/ectypes.h>
#include <erty/string/ecstring.h>

cstr_t eitoa(i64_t nb, cstr_t tofill, cstr_t base)
{
    size_t i = 0;
    size_t size_base = estrlen(base);
    bool isneg = false;

    if (nb < 0) {
        nb = -nb;
        isneg = true;
    }
    do {
        tofill[i] = base[nb % size_base];
        i++;
        nb /= size_base;
    } while (nb > 0);
    if (isneg)
        tofill[i++] = '-';
    tofill[i] = '\0';
    return (erevstr(tofill));
}