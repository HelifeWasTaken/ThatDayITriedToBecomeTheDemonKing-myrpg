/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** at
*/

#include <erty/string/esstring.h>

cstr_t at_sstr(const string_t *this, size_t pos)
{
    if (pos >= this->size)
        return (NULL);
    return (this->str + pos);
}