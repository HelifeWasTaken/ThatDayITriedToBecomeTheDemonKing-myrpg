/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ewrite
*/

#include <erty/ewrite.h>

ssize_t ewrite(fd_t fd, void const *buf, size_t size)
{
    return (write(fd, buf, size));
}