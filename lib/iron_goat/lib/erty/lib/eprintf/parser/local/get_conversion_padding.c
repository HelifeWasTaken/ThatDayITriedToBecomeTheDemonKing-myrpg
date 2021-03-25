/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** get_conversion_padding
*/

#include <erty/eprintf.h>
#include <erty/estdlib.h>

void get_signed_conversion_padding(i64_t v, i32_t len, eprintf_mod_t *mod)
{
    i32_t max_len_precision = 0;

    if (mod->modflag.plus && v >= 0)
        GET_NEW_SIGNED_PADDING(mod->modflag.pad.size, 1);
    if (mod->modflag.space)
        GET_NEW_SIGNED_PADDING(mod->modflag.pad.size, 1);
    if (mod->modflag.precision != -1)
        GET_NEW_SIGNED_PADDING(mod->modflag.precision, len);
    max_len_precision = MAX(mod->modflag.precision, len);
    GET_NEW_SIGNED_PADDING(mod->modflag.pad.size, max_len_precision);
}

void get_unsigned_conversion_padding(i32_t len, eprintf_mod_t *mod)
{
    int max_len_precision = 0;

    if (mod->modflag.plus)
        GET_NEW_UNSIGNED_PADDING(mod->modflag.pad.size, 1);
    if (mod->modflag.space)
        GET_NEW_UNSIGNED_PADDING(mod->modflag.pad.size, 1);
    if (mod->modflag.precision != -1)
        GET_NEW_UNSIGNED_PADDING(mod->modflag.precision, len);
    max_len_precision = MAX(mod->modflag.precision, len);
    GET_NEW_UNSIGNED_PADDING(mod->modflag.pad.size, max_len_precision);
}