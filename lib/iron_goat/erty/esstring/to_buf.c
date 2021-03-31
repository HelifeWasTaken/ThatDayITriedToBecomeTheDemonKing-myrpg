/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** to_buf
*/

#include <erty/string/esstring.h>

cstr_t sstr_to_buf(string_t *this)
{
    cstr_t res = NULL;

    res = this->str;
    this->size = 0;
    this->str = NULL;
    return (res);
}