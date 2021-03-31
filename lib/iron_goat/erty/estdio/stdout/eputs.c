/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** eputs
*/

#include <erty/efile.h>

ssize_t eputs(const_cstr_t str)
{
    return (efputs(stdout, str));
}