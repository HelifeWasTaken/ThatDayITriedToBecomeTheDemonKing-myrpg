/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** edputstr
*/

#include <erty/efd.h>
#include <erty/string/ecstring.h>

ssize_t edputs(fd_t fd, const_cstr_t buf)
{
    return (ewrite(fd, buf, estrlen(buf)) + edputchar(fd, '\n'));
}