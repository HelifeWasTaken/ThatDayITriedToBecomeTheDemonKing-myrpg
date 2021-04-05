/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** convert_wchr_to_chr
*/

#include <erty/ewchar.h>

char convert_wchr_to_chr(wchar_t c)
{
    char s = 0;
    __mbstate_t wcs;

    wcs.__value.__wch = c;
    if (!wcs.__value.__wchb[0])
        return (s);
    s += wcs.__value.__wchb[0];
    if (!wcs.__value.__wchb[1])
        return (s);
    s += (wcs.__value.__wchb[1] >> 8);
    if (!wcs.__value.__wchb[2])
        return (s);
    s += (wcs.__value.__wchb[1] >> 16);
    if (!wcs.__value.__wchb[3])
        return (s);
    return (s + (wcs.__value.__wchb[1] >> 24));
}
