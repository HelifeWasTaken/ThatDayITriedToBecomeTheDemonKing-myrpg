/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** evprintf
*/

#include <erty/eprintf.h>

i32_t evprintf(const_cstr_t format, va_list *ap)
{
    return (evfprintf(stdout, format, ap));
}