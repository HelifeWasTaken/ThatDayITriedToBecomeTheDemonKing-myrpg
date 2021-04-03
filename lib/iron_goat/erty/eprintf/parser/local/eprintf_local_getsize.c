/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf_local_getsize
*/

#include <erty/eprintf.h>

void eprintf_local_getsize(ebuff_t **buff, va_list *ap)
{
    i32_t *size = va_arg(*ap, i32_t *);

    *size = eget_buffused(*buff);
}