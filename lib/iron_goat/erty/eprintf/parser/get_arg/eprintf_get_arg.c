/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eprintf_get_arg
*/

#include <erty/eprintf.h>

int64_t get_signed_arg(va_list *ap, u8_t mod)
{
    union eprintf_arg arg = get_eprintf_ptr(ap);

    switch (mod) {
        case EPRINTF_MOD_CHAR:
            return (arg.chr);
        case EPRINTF_MOD_SHORT:
            return (arg.shrt);
        case EPRINTF_MOD_LONG:
            return (arg.lng);
        case EPRINTF_MOD_LONG_LONG:
            return (arg.llng);
        case EPRINTF_MOD_LONG_DOUBLE:
            return (arg.dble);
        case EPRINTF_MOD_SIZE_T:
            return (arg.st);
        case EPRINTF_MOD_INTMAX:
            return (arg.imax);
        default:
            return (arg.i);
    }
}

uint64_t get_unsigned_arg(va_list *ap, u8_t mod)
{
    union eprintf_arg arg = get_eprintf_ptr(ap);

    switch (mod) {
        case EPRINTF_MOD_CHAR:
            return (arg.uchr);
        case EPRINTF_MOD_SHORT:
            return (arg.ushrt);
        case EPRINTF_MOD_LONG:
            return (arg.ulng);
        case EPRINTF_MOD_LONG_LONG:
            return (arg.ullng);
        case EPRINTF_MOD_SIZE_T:
            return (arg.st);
        case EPRINTF_MOD_PTRDIFF_T:
            return (arg.ptrdiff);
        case EPRINTF_MOD_INTMAX:
            return (arg.uimax);
        default:
            return (arg.ui);
    }
}

void *get_ptr_arg(va_list *ap, u8_t mod)
{
    union eprintf_arg arg = get_eprintf_ptr(ap);

    switch (mod) {
        case EPRINTF_MOD_LONG:
        case EPRINTF_MOD_LONG_LONG:
            return (arg.wstr);
        default:
            return (arg.str);
    }
}