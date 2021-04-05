/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** eprintf_global_buff
*/

#include <erty/ebuffer.h>

ebuff_t **eprintf_global_buff(void)
{
    static ebuff_t *buff = NULL;

    return (&buff);
}