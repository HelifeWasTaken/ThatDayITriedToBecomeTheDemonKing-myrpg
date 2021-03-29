/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** get_eprintf_len_flag
*/

#include <erty/string/ecstring.h>
#include <erty/eprintf.h>

static const char known_flag[10][2] = {
    "hh", "h", "l", "ll", "q",
    "L", "j", "z", "Z", "t"
};

static const u_int8_t len_flags[10] = {
    2, 1, 1, 2, 1,
    1, 1, 1, 1, 1
};

static const u_int8_t ids[10] = {
    EPRINTF_MOD_CHAR, EPRINTF_MOD_SHORT,
    EPRINTF_MOD_LONG, EPRINTF_MOD_LONG_LONG, EPRINTF_MOD_LONG_LONG,
    EPRINTF_MOD_LONG_DOUBLE, EPRINTF_MOD_INTMAX, EPRINTF_MOD_SIZE_T,
    EPRINTF_MOD_SIZE_T, EPRINTF_MOD_PTRDIFF_T
};

void mod_eprintf_len_flags(const_cstr_t*format, eprintf_mod_t *mod)
{
    for (u8_t i = 0; i < 8; i++) {
        if (HAS_SAME_FORMAT(format, mod->offset, known_flag[i], len_flags[i])) {
            consume_format_char(format, len_flags[i]);
            mod->len = ids[i];
            return;
        }
    }
    mod->len = EPRINTF_MOD_DEFAULT;
}