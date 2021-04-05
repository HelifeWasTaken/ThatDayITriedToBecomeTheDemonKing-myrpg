/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eatoi
*/

#include <erty/ectypes.h>
#include <erty/estdlib.h>

OPT(i32) eatoi(const_cstr_t str)
{
    OPT(i64) v = eatol(str);

    return ((OPT(i32)){v.value, v.is_ok});
}
