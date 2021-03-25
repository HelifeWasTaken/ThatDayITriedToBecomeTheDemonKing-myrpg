/*
** EPITECH PROJECT, 2021
** copy_tab
** File description:
** cp
*/

#include <erty/string/ecstring.h>

cstr_t *ecopy_tab(cstr_t *tab)
{
    size_t i = 0;
    cstr_t *copy = emalloc(sizeof(cstr_t) * (ecount_tab(tab) + 1));

    if (copy == NULL)
        return (NULL);
    for (; tab[i]; i++) {
        if ((copy[i] = estrdup(tab[i])) == NULL)
            return (NULL);
    }
    tab[i] = NULL;
    return (copy);
}
