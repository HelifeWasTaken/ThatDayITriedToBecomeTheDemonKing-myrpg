/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ewcslen
*/

#include <erty/ewchar.h>

size_t ewcslen(wchar_t const *wcs)
{
    size_t len = 0;

    while (wcs[len] != L'\0') {
        if (wcs[++len] == L'\0')
            return (len);
        if (wcs[++len] == L'\0')
            return (len);
        if (wcs[++len] == L'\0')
            return (len);
        len++;
    }
    return (len);
}
