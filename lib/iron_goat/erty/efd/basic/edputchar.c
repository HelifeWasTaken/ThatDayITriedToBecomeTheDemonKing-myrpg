/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** edputchar
*/

#include <erty/ewrite.h>
#include <erty/ectypes.h>

ssize_t edputchar(fd_t fd, i32_t c)
{
    return (ewrite(fd, &c, 1));
}