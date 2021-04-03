/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eduputnbr
*/

#include <erty/efd.h>

size_t eduputnbr(fd_t fd, u64_t nb)
{
    return ((nb >= 10) ?
        eduputnbr(fd, nb / 10) + edputchar(fd, nb % 10 + '0') :
        (size_t)edputchar(fd, nb + '0'));
}