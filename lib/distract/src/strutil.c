/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Compare one string with another
*/

#include "distract/util.h"
#include "sys/types.h"
#include <stddef.h>

size_t dstrlen(char const *s)
{
    size_t i = 0;

    if (s)
        for (; s[i]; i++);
    return (i);
}

int dstrcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            i++;
            continue;
        }
        if (s1[i] > s2[i])
            return (1);
        return (-1);
    }
    return (0);
}

char *dstrdup(char const *src)
{
    char *dest = dmalloc(sizeof(char) * (dstrlen(src) + 1));
    size_t i = 0;

    if (dest == NULL)
        return (NULL);
    do {
        dest[i] = src[i];
    } while (src[i++]);
    return (dest);
}
