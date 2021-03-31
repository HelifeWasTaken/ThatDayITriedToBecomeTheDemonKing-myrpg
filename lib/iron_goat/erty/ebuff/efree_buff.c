/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** efree_buff
*/


#include <erty/ebuffer.h>

void efree_buff(ebuff_t **buff_info)
{
    if (*buff_info) {
        if ((*buff_info)->buff_size) {
            ereset_buff(buff_info);
            efree((*buff_info)->buff);
            (*buff_info)->buff = NULL;
            (*buff_info)->buff_size = 0;
        }
        efree(*buff_info);
        *buff_info = NULL;
    }
}