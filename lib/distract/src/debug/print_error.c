/*
** EPITECH PROJECT, 2020
** print_error
** File description:
** Source code
*/
#include "unistd.h"

int len(char *str)
{
    size_t i = 0;

    if (str)
        for (; str[i]; i++);
    return (i);
}

void print_error(char *error)
{
    (void)error;
}
