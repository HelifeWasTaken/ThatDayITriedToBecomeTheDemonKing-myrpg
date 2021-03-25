/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf_local_ptr
*/

#include <erty/eprintf.h>

void eprintf_local_ptr(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod)
{
    mod->len = EPRINTF_MOD_LONG;
    eappend_buff_str(buff, "0x");
    eprintf_local_hex_min(buff, ap, mod);
}