/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** eprintf_buffer_reset
*/

#include <erty/ebuffer.h>

void eprintf_buffer_reset(ebuff_t **buff, bool flush, fd_t fd)
{
    if (*buff == NULL) {
        *buff = ecreate_buff(NULL, flush, fd);
    } else {
        ereset_buff(buff);
        (*buff)->fd = fd;
        (*buff)->flush = flush;
    }
}
