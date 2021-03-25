/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eshowptr
*/

#include <erty/efile.h>

size_t eshowptr(unsigned long long ptrvalue)
{
    return (efwrite(stdout, "0x", 2) + efputnbr(stdout, ptrvalue));
}