/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** evasprintf
*/

#include <erty/eprintf.h>
#include <erty/eassert.h>
#include <erty/estdlib.h>

i32_t evasprintf(cstr_t *buff, const_cstr_t format, va_list *ap)
{
    ebuff_t **buff_info = NULL;

    FREE(*buff);
    if (!check_eprintf_format(format)) {
        *buff = estrdup(format);
        return ((*buff) ? (ssize_t)estrlen(*buff) :
            PRINTF_FAIL("evasprintf"));
    }
    buff_info = eprintf_parser(format, false, -1, ap);
    if (buff_info != NULL && *buff_info != NULL && (*buff_info)->buff) {
        *buff = edup_buff(*buff_info);
        if ((*buff_info)->buff_size >= BUFF_CHUNK * 2)
            efree_buff(buff_info);
        return ((*buff) ? (signed int)estrlen(*buff) :
            PRINTF_FAIL("evasprintf"));
    }
    return (PRINTF_FAIL("evasprintf"));
}