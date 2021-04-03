/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** efputstr
*/

#include <erty/string/ecstring.h>
#include <erty/efile.h>

ssize_t efputs(FILE *stream, const_cstr_t buf)
{
    return (efwrite(stream, buf, estrlen(buf)) + efputchar(stream, '\n'));
}