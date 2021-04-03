/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estrcat
*/

#include <erty/string/ecstring.h>

cstr_t estrcat(cstr_t dest, const_cstr_t src)
{
    estrcpy(dest + estrlen(dest), src);
    return (dest);
}