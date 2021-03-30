/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eget_start_sign
*/

#include <erty/ectypes.h>

int eget_start_sign(const_cstr_t str, i32_t *index)
{
    if (*str == '-') {
        *index += 1;
        return (-1);
    }
    return (1);
}