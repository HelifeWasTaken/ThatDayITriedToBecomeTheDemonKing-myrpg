/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** evfprintf
*/

#include <erty/eprintf.h>

i32_t evfprintf(FILE *stream, const_cstr_t format, va_list *ap)
{
    if (!stream)
        return (PRINTF_FAIL("evfprintf"));
    return (evdprintf(stream->_fileno, format, ap));
}