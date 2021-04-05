/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf_local_char
*/

#include <erty/eprintf.h>

void eprintf_local_char(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod)
{
    wchar_t wchr = get_signed_arg(ap, mod->len);
    wchr = convert_wchr_to_chr(wchr);

    if (mod->modflag.pad.left) {
        eprintf_append_padding(buff, mod->modflag.pad.size, false);
        eappend_buff_char(buff, wchr);
    } else {
        eappend_buff_char(buff, wchr);
        eprintf_append_padding(buff, mod->modflag.pad.size, false);
    }
}