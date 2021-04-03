/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eappend_buff
*/

#include <erty/ebuffer.h>

ssize_t eappend_buff_nbytes(ebuff_t **buff_info, cstr_t toadd, size_t n)
{
    cstr_t ptr = NULL;

    if (!(*buff_info))
        return (-1);
    if (n > (*buff_info)->buff_size - ((*buff_info)->used + 2)) {
        if ((*buff_info)->flush) {
            eflush_buff(buff_info);
            ereset_buff(buff_info);
        } else
            erealloc_buff(buff_info, n);
    }
    if (!(*buff_info)->buff)
        return (-1);
    ptr = (*buff_info)->buff;
    ememcpy((*buff_info)->buff + (*buff_info)->used, toadd, n);
    (*buff_info)->buff = ptr;
    (*buff_info)->used += n;
    return (0);
}

ssize_t eappend_buff_str(ebuff_t **buff_info, cstr_t toadd)
{
    return (eappend_buff_nbytes(buff_info, toadd, estrlen(toadd)));
}

ssize_t eappend_buff_char(ebuff_t **buff_info, i32_t c)
{
    return (eappend_buff_nbytes(buff_info, (cstr_t)&c, 1));
}

ssize_t eappend_buff_unsigned_number(ebuff_t **buff,
        u64_t nb, char const *base, u8_t base_size)
{
    return ((nb >= base_size) ?
            eappend_buff_unsigned_number(
                buff, nb / base_size, base, base_size) +
            eappend_buff_char(buff, base[nb % base_size]) :
            eappend_buff_char(buff, base[nb]));
}

ssize_t eappend_buff_signed_number(ebuff_t **buff,
        i64_t nb, char const *base, u8_t base_size)
{
    return ((nb >= 0) ?
            eappend_buff_unsigned_number(buff, nb, base, base_size) :
            eappend_buff_char(buff, '-') +
            eappend_buff_unsigned_number(buff, -nb, base, base_size));
}
