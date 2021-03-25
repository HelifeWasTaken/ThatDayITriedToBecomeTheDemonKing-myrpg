/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** compare
*/

#include <erty/string/esstring.h>

i32_t compare_cstr(const string_t *this, const_cstr_t cstring)
{
    return (estrcmp(this->str, cstring));
}