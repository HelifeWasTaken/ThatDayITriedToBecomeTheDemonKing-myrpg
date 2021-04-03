/*
** EPITECH PROJECT, 2021
** liberty
** File description:
** eappend_tab.c
*/

#include <erty/ealloc.h>
#include <erty/string/ecstring.h>

static char **create_tab(cstr_t src)
{
    char **map = NULL;

    if ((map = emalloc(sizeof(cstr_t) * 2)) != NULL) {
        map[0] = estrdup(src);
        map[1] = NULL;
    }
    return (map);
}

char **eappend_tab(cstr_t **tab, cstr_t src)
{
    size_t i = 0;
    cstr_t *new = NULL;

    if (*tab == NULL) {
        *tab = create_tab(src);
        return (*tab);
    }
    if ((new = emalloc(sizeof(cstr_t) * (ecount_tab(*tab) + 2))) == NULL)
        return (NULL);
    for (; (*tab)[i]; i++) {
        if ((new[i] = estrdup((*tab)[i])) == NULL)
            return (NULL);
    }
    new[i] = estrdup(src);
    new[i + 1] = NULL;
    free_esplit(*tab);
    *tab = new;
    return (*tab);
}
