/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** assign_n
*/

#include <erty/string/esstring.h>

ssize_t assign_n_from_cstr(string_t *this, const_cstr_t s, size_t n)
{
    if (this->str)
        efree(this->str);
    this->str = estrndup(s, n);
    this->size = estrlen(this->str);
    if (this->str)
        return (this->size);
    return (-1);
}