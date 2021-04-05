/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** esprintf
*/

#include <erty/eprintf.h>
#include <erty/string/ecstring.h>

i32_t easprintf(cstr_t *buff, const_cstr_t format, ...)
{
    i32_t result = EPRINTF_FAILURE;
    va_list ap;

    va_start(ap, format);
    result = evasprintf(buff, format, &ap);
    va_end(ap);
    return ((*buff) ? result : EPRINTF_FAILURE);
}