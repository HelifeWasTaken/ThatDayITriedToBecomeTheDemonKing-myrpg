/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ememcpy
*/

#include <erty/ectypes.h>

void *ememcpy(void *dest, void const *src, size_t size)
{
    ucstr_t dest_s = (ucstr_t)dest;
    ucstr_t src_s = (ucstr_t)src;

    while (size--)
        *dest_s++ = *src_s++;
    return (dest);
}