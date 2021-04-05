/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** econcat
*/

#include <erty/string/ecstring.h>
#include <erty/eassert.h>

static void copy_data_on_success(char *buf, char *s1, char *s2)
{
    size_t size_s1 = estrlen(s1);
    size_t size_s2 = estrlen(s2);

    buf = emalloc(sizeof(char) * (size_s1 + size_s2 + 1));

    if (buf == NULL) {
        ASSERT("Erty", "Memory allocation failed");
        return;
    }
    estrcpy(buf, s1);
    estrcat(buf + size_s1, s2);
    buf[size_s1 + size_s2] = '\0';
    efree(s1);
    efree(s2);
}

cstr_t econcat(cstr_t s1, cstr_t s2)
{
    cstr_t buf = NULL;

    if (s2 == NULL)
        return (NULL);
    if (s1 == NULL) {
        buf = estrdup(s2);
        if (buf == NULL)
            ASSERT("Erty", "Memory allocation failed");
        efree(s2);
        return (buf);
    }
    copy_data_on_success(buf, s1, s2);
    return (buf);
}
