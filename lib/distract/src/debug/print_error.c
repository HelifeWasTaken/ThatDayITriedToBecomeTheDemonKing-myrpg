/*
** EPITECH PROJECT, 2020
** print_error
** File description:
** Source code
*/
#include "unistd.h"

static int len(char *str)
{
    size_t i = 0;

    if (str)
        for (; str[i]; i++);
    return (i);
}

void print_error(char *error)
{
    write(2, "[ERR]  ", 7);
    write(2, error, len(error));
    write(2, "\n", 1);
}
