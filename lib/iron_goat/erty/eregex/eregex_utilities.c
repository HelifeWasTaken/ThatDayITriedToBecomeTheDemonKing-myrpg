/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** eregex_util
*/

#include <erty/eregex.h>
#include <erty/string/ecstring.h>

int rgx_match(char *expr, char const *regexpr)
{
    char *useless = NULL;
    char *useless2 = NULL;

    return (regex(expr, regexpr, &useless, &useless2));
}

char *rgx_str(char *expr, char const *regexpr)
{
    char *start = NULL;
    char *end = NULL;
    char *result = NULL;

    if (regex(expr, regexpr, &start, &end) == 1) {
        result = estrndup(start, end - start);
        if (result == NULL)
            return ((char *)-1);
    }
    return (result);
}
