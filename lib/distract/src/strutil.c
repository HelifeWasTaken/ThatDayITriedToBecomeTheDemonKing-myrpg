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
    return (*s != '\0' ? dstrlen(s + 1) + 1 : 0);
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
    size_t len = dstrlen(src);
    char *dest = dmalloc(len + 1);
    
    if (dest == NULL)
        return (NULL);
    while (len) {
        dest[len - 1] = src[len - 1];
        len--;
    }
    return (dest);
}