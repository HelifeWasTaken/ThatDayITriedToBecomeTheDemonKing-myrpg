/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ereset_buff
*/

#include <erty/ebuffer.h>

void ereset_buff(ebuff_t **buff_info)
{
    if (*buff_info) {
        if ((*buff_info)->buff)
            ebzero((*buff_info)->buff, sizeof(char) * (*buff_info)->used);
        (*buff_info)->used = 0;
    }
}