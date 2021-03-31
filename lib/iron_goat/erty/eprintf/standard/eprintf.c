/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf
*/

#include <erty/eprintf.h>

i32_t eprintf(const_cstr_t format, ...)
{
    i32_t result = EPRINTF_FAILURE;
    va_list ap;

    va_start(ap, format);
    result = evprintf(format, &ap);
    va_end(ap);
    return (result);
}