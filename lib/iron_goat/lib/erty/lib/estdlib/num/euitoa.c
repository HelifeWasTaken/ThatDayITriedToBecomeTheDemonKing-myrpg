/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** euitoa
*/

#include <erty/ectypes.h>
#include <erty/string/ecstring.h>

cstr_t euitoa(u64_t nb, cstr_t tofill, cstr_t base)
{
    size_t i = 0;
    size_t size_base = estrlen(base);

    do {
        tofill[i] = base[nb % size_base];
        i++;
        nb /= size_base;
    } while (nb > 0);
    tofill[i] = '\0';
    return (erevstr(tofill));
}