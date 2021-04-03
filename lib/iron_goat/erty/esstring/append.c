/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** append
*/

#include <erty/string/esstring.h>

ssize_t append_cstr(string_t *this, const_cstr_t cstring)
{
    cstr_t tmp = NULL;

    if (!cstring)
        return (-1);
    if (!this->str) {
        this->str = estrdup(cstring);
        this->size = estrlen(cstring);
    } else {
        tmp = ECONCAT(this->str, cstring);
        efree(this->str);
        this->str = tmp;
        this->size = estrlen(tmp);
    }
    if (this->str)
        return (this->size);
    return (-1);
}