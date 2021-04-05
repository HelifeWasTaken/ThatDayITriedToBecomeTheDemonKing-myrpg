/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eauitoa
*/

#include <erty/string/ecstring.h>
#include <erty/estdlib.h>

cstr_t eauitoa(u64_t nb, const_cstr_t base)
{
    cstr_t nbstr = emalloc(sizeof(char) * (enb_baselen(nb, estrlen(base)) + 1));

    if (nbstr)
        euitoa(nb, nbstr, base);
    return (nbstr);
}