/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** estr_strcapitalize
*/

#include <erty/string/ecstring.h>

cstr_t estr_capitalize(cstr_t src)
{
    cstr_t str = estrdup(src);
    bool in_word = false;

    for (size_t i = 0; str[i]; i++) {
        if (!in_word && eis_alphanum(str[i])) {
            in_word = true;
            str[i] = eto_upper(str[i]);
            continue;
        }
        if (in_word && !eis_alphanum(str[i])) {
            in_word = false;
            str[i] = eto_upper(str[i]);
            continue;
        }
        if (in_word && eis_alphanum(str[i])) {
            str[i] = eto_lower(str[i]);
            continue;
        }
    }
    return (str);
}