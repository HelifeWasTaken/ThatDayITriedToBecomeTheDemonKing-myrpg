/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf_append_padding
*/

#include <erty/eprintf.h>
#include <erty/string/ecstring.h>

void eprintf_append_padding(ebuff_t **buff, i32_t size, bool iszero)
{
    if (size <= 0)
        return;
    for (i32_t i = 0; i < size; i++)
        eappend_buff_char(buff, (iszero) ? '0' : ' ');
}
