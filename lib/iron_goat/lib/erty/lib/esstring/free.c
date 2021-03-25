/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** free
*/

#include <erty/string/esstring.h>

void free_sstr(string_t *this)
{
    efree(this->str);
    this->str = NULL;
    this->size = 0;
}
