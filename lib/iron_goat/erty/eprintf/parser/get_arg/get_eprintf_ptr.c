/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** get_eprintf_ptr
*/

#include <erty/eprintf.h>

union eprintf_arg get_eprintf_ptr(va_list *ap)
{
    union eprintf_arg arg;

    arg.ptr = va_arg(*ap, usize_t);
    return (arg);
}