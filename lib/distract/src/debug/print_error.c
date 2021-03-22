/*
** EPITECH PROJECT, 2020
** print_error
** File description:
** Source code
*/
#include "unistd.h"

static int len(char *str)
{
    return (*str == '\0' ? 0 : len(str + 1) + 1);
}

void print_error(char *error)
{
    write(2, "[ERR]  ", 7);
    write(2, error, len(error));
    write(2, "\n", 1);
}