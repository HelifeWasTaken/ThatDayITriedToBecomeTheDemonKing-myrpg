/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf_local_hex
*/

#include <erty/eprintf.h>
#include <erty/string/ecstring.h>
#include <erty/estdlib.h>

static void eprintf_local_oct_padding_left(ebuff_t **buff,
    eprintf_mod_t *mod, u64_t value)
{
    (mod->modflag.space) ? eappend_buff_str(buff, " ") : 0;
    if (mod->modflag.zero) {
        (mod->modflag.plus) ? eappend_buff_str(buff, "+") : 0;
        eprintf_append_padding(buff, mod->modflag.precision, true);
        eprintf_append_padding(buff, mod->modflag.pad.size, true);
    } else {
        eprintf_append_padding(buff, mod->modflag.pad.size, false);
        (mod->modflag.plus) ? eappend_buff_str(buff, "+") : 0;
        eprintf_append_padding(buff, mod->modflag.precision, true);
    }
    (mod->modflag.hashtag) ? eappend_buff_str(buff, "0x") : 0;
    eappend_buff_unsigned_number(buff, value, "01234567", 8);
}

static void eprintf_local_oct_padding_right(ebuff_t **buff,
        eprintf_mod_t *mod, u64_t value)
{
    (mod->modflag.plus) ? eappend_buff_str(buff, "+") : 0;
    eprintf_append_padding(buff, mod->modflag.precision, true);
    (mod->modflag.hashtag) ? eappend_buff_str(buff, "0x") : 0;
    eappend_buff_unsigned_number(buff, value, "01234567", 8);
    (mod->modflag.space) ? eappend_buff_str(buff, " ") : 0;
    eprintf_append_padding(buff, mod->modflag.pad.size, false);
}

void eprintf_local_oct(ebuff_t **buff, va_list *ap, eprintf_mod_t *mod)
{
    u64_t value = get_unsigned_arg(ap, mod->len);

    SET_PRECISION(mod->modflag.precision, 0);
    get_unsigned_conversion_padding(eunb_baselen(value, 8), mod);
    if (mod->modflag.pad.right)
        eprintf_local_oct_padding_right(buff, mod, value);
    else
        eprintf_local_oct_padding_left(buff, mod, value);
}
