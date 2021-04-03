/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** efprintf
*/

#include <erty/eprintf.h>

i32_t efprintf(FILE *stream, const_cstr_t format, ...)
{
    i32_t result = EPRINTF_FAILURE;
    va_list ap;

    if (!stream || stream->_fileno < 0)
        return (EPRINTF_FAILURE);
    va_start(ap, format);
    result = evfprintf(stream, format, &ap);
    va_end(ap);
    return (result);
}