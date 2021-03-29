/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf_local_str
*/

#include <erty/eprintf.h>
#include <erty/string/ecstring.h>

void eprintf_local_str(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod)
{
    cstr_t s = get_ptr_arg(ap, mod->len);
    size_t size_s = estrlen(s);

    mod->modflag.pad.size = (mod->modflag.pad.right - size_s > 0) ?
        mod->modflag.pad.size - size_s : 0;
    if (mod->modflag.pad.left) {
        eprintf_append_padding(buff, mod->modflag.pad.size, false);
        eappend_buff_str(buff, s);
    } else {
        eappend_buff_str(buff, s);
        eprintf_append_padding(buff, mod->modflag.pad.size, false);
    }
}