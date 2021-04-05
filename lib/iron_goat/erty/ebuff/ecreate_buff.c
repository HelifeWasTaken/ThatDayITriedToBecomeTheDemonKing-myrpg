/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ecreate_buff
*/

#include <erty/ebuffer.h>
#include <erty/ealloc.h>
#include <erty/eassert.h>

ebuff_t *ecreate_buff(cstr_t buffer, bool flush, fd_t fd)
{
    ebuff_t *buff_info = ecalloc(sizeof(ebuff_t), 1);

    if (!buff_info)
        return (NULL);
    if (buff_info->buff)
        efree_buff(&buff_info);
    if (!buffer) {
        buff_info->buff = ecalloc(sizeof(char), BUFF_CHUNK);
        buff_info->buff_size = BUFF_CHUNK;
    } else {
        buff_info->buff = buffer;
        buff_info->buff_size = estrlen(buffer);
    }
    if (buff_info->buff == NULL)
        ASSERT("Erty", "Memory Allocation failed for buffer!");
    buff_info->flush = flush;
    buff_info->fd = fd;
    return (buff_info);
}
