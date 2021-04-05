/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** get_eprintf_flag_modifiers
*/

#include <erty/eprintf.h>
#include <erty/estdlib.h>
#include <erty/string/ecstring.h>

static bool check_eprintf_flag_modifiers(eprintf_modflag_t *mod, char const c)
{
    switch (c) {
        case '0':
            mod->zero = true;
            return (true);
        case '-':
            mod->minus = true;
            return (true);
        case ' ':
            mod->space = true;
            return (true);
        case '+':
            mod->plus = true;
            return (true);
        default:
            return (false);
    }
}

static void get_eprintf_precision(const_cstr_t*format,
    eprintf_mod_t *mod, va_list *ap)
{
    OPT(u64) precision;

    if (get_char_format_at_index(format, mod->offset) != '.')
        return;
    mod->offset++;
    if (get_char_format_at_index(format, mod->offset) == '*') {
        mod->modflag.precision = va_arg(*ap, unsigned int);
        for (; eis_num(get_char_format_at_index(format, mod->offset));
            mod->offset++);
        return;
    }
    if (eis_num(get_char_format_at_index(format, mod->offset))) {
        precision = euatol((*format) + mod->offset);
        if (precision.is_ok) {
            mod->modflag.precision = precision.value;
            for (; eis_num(get_char_format_at_index(format, mod->offset));
                mod->offset++);
        }
    }
}

static void get_eprintf_padding(const_cstr_t*format,
    eprintf_mod_t *mod, va_list *ap)
{
    OPT(u64) padding;

    if (get_char_format_at_index(format, mod->offset) == '*') {
        mod->modflag.pad.size = va_arg(*ap, unsigned int);
        for (; eis_num(get_char_format_at_index(format, mod->offset));
            mod->offset++);
        return;
    }
    if (eis_num(get_char_format_at_index(format, mod->offset))) {
        padding = euatol(*format);
        if (padding.is_ok) {
            mod->modflag.pad.size = padding.value;
            for (; eis_num(get_char_format_at_index(format, mod->offset));
                mod->offset++);
        }
    }
}

static void parse_eprintf_flag_modifiers(eprintf_modflag_t *mod)
{
    if (mod->minus) {
        mod->zero = false;
        mod->pad.left = false;
        mod->pad.right = true;
    }
    if (mod->precision != -1)
        mod->zero = false;
    if (mod->plus)
        mod->space = false;
}

void get_eprintf_flag_modifiers(const_cstr_t*format,
    eprintf_mod_t *mod, va_list *ap)
{
    eprintf_modflag_t modflag = {0};

    modflag.precision = -1;
    modflag.pad.left = true;
    while (check_eprintf_flag_modifiers(&modflag,
        get_char_format_at_index(format, mod->offset)))
        mod->offset++;
    mod->modflag = modflag;
    get_eprintf_padding(format, mod, ap);
    get_eprintf_precision(format, mod, ap);
    parse_eprintf_flag_modifiers(&mod->modflag);
}
