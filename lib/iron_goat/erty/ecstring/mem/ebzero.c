/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ebzero
*/

#include <erty/string/ecstring.h>

void *ebzero(void *ptr, size_t size)
{
    return (ememset(ptr, 0, size));
}