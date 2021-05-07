/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** assign_n
*/

#include <erty/string/esstring.h>

#include <stdio.h>
static void append_n_from_cstr_both(string_t *this, const_cstr_t s, size_t n)
{
    cstr_t tmp = emalloc(sizeof(char) * (this->size + n + 1));

    if (tmp) {
        ememcpy(tmp, this->str, this->size);
        ememcpy(tmp + this->size, s, n);
        tmp[this->size + n] = 0;
        this->size += n;
    }
    efree(this->str);
    this->str = tmp;
}

ssize_t append_n_from_cstr(string_t *this, const_cstr_t s, size_t n)
{
    if (!s)
        return (-1);
    if (!this->str) {
        this->str = estrndup(s, n);
        this->size = n;
    } else
        append_n_from_cstr_both(this, s, n);
    if (this->str)
        return (this->size);
    return (-1);
}
