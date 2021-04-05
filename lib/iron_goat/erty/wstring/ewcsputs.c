/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ewcswrite
*/

#include <erty/ewchar.h>
#include <erty/ewrite.h>

size_t ewcsputs(int fd, void const *buf)
{
    size_t size = ewcslen((wchar_t const *)buf);
    char buffer[size];

    ewcstombs(buffer, (wchar_t const *)buf, size);
    return (ewrite(fd, buf, size));
}