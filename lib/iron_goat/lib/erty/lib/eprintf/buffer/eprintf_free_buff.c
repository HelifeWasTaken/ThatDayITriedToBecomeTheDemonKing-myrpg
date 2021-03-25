/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** eprintf_free_buff
*/

#include <erty/eprintf.h>

void eprintf_free_buff(void)
{
    efree_buff(eprintf_global_buff());
}
