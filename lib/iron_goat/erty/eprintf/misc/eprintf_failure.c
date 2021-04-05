/*
** EPITECH PROJECT, 2021
** epr
** File description:
** fail
*/

#include <erty/eprintf.h>
#include <erty/eassert.h>
#include <erty/estdio.h>

int eprintf_failure(char *prg, char *file, int line)
{
    efwrite(stderr, "\033[31m[", estrlen("\033[31m["));
    efwrite(stderr, prg, estrlen(prg));
    efwrite(stderr, ": Has gotten a fatal error", 26);
    efwrite(stderr, "]\033[33m ", estrlen("]\033[31m"));
    efwrite(stderr, file, estrlen(file));
    efputchar(stderr, ':');
    efputnbr(stderr, line);
    efputs(stderr, "\033[0;m");
    return (EPRINTF_FAILURE);
}