/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ememset
*/

#include <erty/ectypes.h>

void *ememset(void *ptr, int c, size_t size)
{
    ucstr_t ptr_s = (ucstr_t)ptr;

    while (size--)
        *ptr_s++ = c;
    return (ptr);
}