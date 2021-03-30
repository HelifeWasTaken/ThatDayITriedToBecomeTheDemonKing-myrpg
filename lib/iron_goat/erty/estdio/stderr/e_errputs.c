/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** e_errputs
*/

#include <erty/efile.h>

ssize_t e_errputs(const_cstr_t str)
{
    return (efputs(stderr, str));
}