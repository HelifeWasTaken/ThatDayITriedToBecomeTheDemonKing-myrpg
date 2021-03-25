/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** assign
*/

#include <erty/string/esstring.h>

ssize_t assign_cstr(string_t *this, const_cstr_t cstring)
{
    if (this->str)
        efree(this->str);
    this->size = estrlen(cstring);
    this->str  = estrdup(cstring);
    if (this->str)
        return (this->size);
    return (-1);
}