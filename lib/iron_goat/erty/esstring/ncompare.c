/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** ncompare
*/

#include <erty/string/esstring.h>

i32_t ncompare_cstr(const string_t *this, const_cstr_t cstring, size_t n)
{
    return (estrncmp(this->str, cstring, n));
}