/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ebuff_flush
*/

#include <erty/ebuffer.h>

ssize_t eflush_buff(ebuff_t **buff_info)
{
    size_t result = -1;

    if (!(*buff_info))
        return (result);
    if (!(*buff_info)->buff || !(*buff_info)->used || (*buff_info)->fd == -1)
        return (-1);
    result = ewrite((*buff_info)->fd, (*buff_info)->buff, (*buff_info)->used);
    return (result);
}
