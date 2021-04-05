/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eptrswap
*/

void eptrswap(void **a, void **b)
{
    void *c = *a;

    *a = *b;
    *b = c;
}