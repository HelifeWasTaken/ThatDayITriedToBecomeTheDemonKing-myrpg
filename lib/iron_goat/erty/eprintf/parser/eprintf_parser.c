/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprint_parser
*/

#include <erty/eprintf.h>

static const struct eprintf_flag_st flags_st[NB_EPRINTF_FLAGS] = {
    {'c',     0,    &eprintf_local_char},
    {'d',   'i',    &eprintf_local_int},
    {'s',   'S',    &eprintf_local_str},
    {'o',     0,    &eprintf_local_oct},
    {'u',     0,    &eprintf_local_uint},
    {'x',     0,    &eprintf_local_hex_min},
    {'X',     0,    &eprintf_local_hex_max},
    {'p',     0,    &eprintf_local_ptr},
    {'f',   'F',    &eprintf_local_double},
};


static ssize_t eprintf_parse_flag(ebuff_t **buffer,
    const_cstr_t*format, va_list *ap)
{
    eprintf_mod_t mod = get_eprintf_modifications(format, ap);

    if (get_char_format_at_index(format, mod.offset) == '\0')
        return (PRINTF_FAIL("eprintf_parse_flag"));
    for (i32_t i = 0; i < NB_EPRINTF_FLAGS; i++) {
        if (IS_SAME_FLAG(format, mod.offset, flags_st, i)) {
            consume_format_char(format, mod.offset + 1);
            (*flags_st[i].fptr_local)(buffer, ap, &mod);
            return (EPRINTF_SUCCESS);
        }
    }
    if (mod.offset == 0 && **format == 'n') {
        eprintf_local_getsize(buffer, ap);
        consume_format_char(format, 1);
        return (EPRINTF_SUCCESS);
    }
    return (PRINTF_FAIL("eprintf_parse_flag"));
}

ebuff_t **eprintf_parser(const_cstr_t format, bool flush, fd_t fd, va_list *ap)
{
    ebuff_t **buffer = eprintf_global_buff();
    i32_t error = EPRINTF_SUCCESS;

    eprintf_buffer_reset(buffer, flush, fd);
    while (*format) {
        if (*format == '%' && *(format + 1) != '%') {
            consume_format_char(&format, 1);
            error = eprintf_parse_flag(buffer, &format, ap);
        } else if (*format == '%' && *(format + 1) == '%') {
            eappend_buff_str(buffer, "%");
            consume_format_char(&format, 2);
        } else {
            eappend_buff_char(buffer, *format);
            consume_format_char(&format, 1);
        }
        if (error != EPRINTF_SUCCESS)
            return (NULL);
    }
    return ((error == EPRINTF_SUCCESS) ? buffer : NULL);
}