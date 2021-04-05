/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eswap
*/

#include <erty/ectypes.h>

void eswap(i32_t *a, i32_t *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}