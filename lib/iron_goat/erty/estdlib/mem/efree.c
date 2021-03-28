/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** efree
*/

#include <stdlib.h>

void efree(void *ptr)
{
    if (ptr)
        free(ptr);
}