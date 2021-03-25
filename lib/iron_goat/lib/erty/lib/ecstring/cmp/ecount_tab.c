/*
** EPITECH PROJECT, 2021
** ecount_tab
** File description:
** count
*/

#include <erty/string/ecstring.h>

size_t ecount_tab(char **tab)
{
    size_t i = 0;

    if (tab)
        for (; tab[i]; i++);
    return (i);
}
