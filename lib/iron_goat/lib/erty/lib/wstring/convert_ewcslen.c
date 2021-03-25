/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** convert_ewcslen
*/

#include <erty/ewchar.h>

size_t convert_ewcslen(wchar_t const *wcs)
{
    return (sizeof(wchar_t) * ewcslen(wcs));
}