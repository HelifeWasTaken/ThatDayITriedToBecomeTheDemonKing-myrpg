/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eget_buff
*/

#include <erty/ebuffer.h>

cstr_t eget_buffstr(ebuff_t *buff_info)
{
    return (buff_info->buff);
}

size_t eget_buffused(ebuff_t *buff_info)
{
    return (buff_info->used);
}

size_t eget_buffusable(ebuff_t *buff_info)
{
    return (buff_info->buff_size);
}

cstr_t edup_buff(ebuff_t *buff_info)
{
    char *s = NULL;

    if (buff_info->buff) {
        s = emalloc(sizeof(char) * (buff_info->used + 1));
        if (s != NULL) {
            ememcpy(s, buff_info->buff, buff_info->used);
            s[buff_info->used] = 0;
        }
        return (s);
    }
    return (NULL);
}
