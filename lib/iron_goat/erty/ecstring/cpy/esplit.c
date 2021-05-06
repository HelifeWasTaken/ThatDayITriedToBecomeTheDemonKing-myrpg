/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** esplit
*/

#include <erty/string/ecstring.h>
#include <erty/string/esstring.h>

void free_esplit(cstr_t *buf)
{
    if (!buf)
        return;
    for (size_t i = 0; buf[i]; i++)
        efree(buf[i]);
    efree(buf);
}

static bool is_token(char const c, char const tokens)
{
    return (c == tokens);
}

static void remove_token(const char **s, char const tokens)
{
    for (; is_token(**s, tokens); (*s)++);
}

static bool get_string(string_t *string, char const **str, char const tokens)
{
    for (; is_token(**str, tokens) == false && **str != '\0'; (*str)++)
        if (string->append_n(string, (char *)(*str), 1) == -1)
            return (false);
    return (true);
}

cstr_t *esplit(const_cstr_t str, char const tokens)
{
    string_t string = init_string(NULL);
    char **tab = NULL;

    while (*str != '\0') {
        string.free(&string);
        remove_token(&str, tokens);
        if (get_string(&string, &str, tokens) == false)
            return (false);
        if (string.str != NULL && string.str[0] != '\0')
            tab = eappend_tab(&tab, string.str);
    }
    string.free(&string);
    return (tab);
}
