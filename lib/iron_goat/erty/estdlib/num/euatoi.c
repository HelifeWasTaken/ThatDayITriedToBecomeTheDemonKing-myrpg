/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** euatoi
*/

#include <erty/estdlib.h>

OPT(u32) euatoi(const_cstr_t str)
{
    OPT(u64) v = euatol(str);

    return ((OPT(u32)){v.value, v.is_ok});
}