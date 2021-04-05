/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eaitoa
*/

#include <erty/string/ecstring.h>
#include <erty/estdlib.h>

cstr_t eaitoa(i64_t nb, const_cstr_t base)
{
    cstr_t nbstr = emalloc(sizeof(char) * (enb_baselen(nb, estrlen(base)) + 1));

    if (nbstr)
        eitoa(nb, nbstr, base);
    return (nbstr);
}