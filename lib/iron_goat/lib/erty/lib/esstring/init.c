/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** init
*/

#include <erty/string/esstring.h>

string_t init_string(char *buffer)
{
    string_t this = {0};

    if (buffer) {
        assign_cstr(&this, buffer);
    } else {
        this.size = 0;
        this.str = NULL;
    }
    this.assign = assign_cstr;
    this.assign_n = assign_n_from_cstr;
    this.append = append_cstr;
    this.append_n = append_n_from_cstr;
    this.at = at_sstr;
    this.compare = compare_cstr;
    this.ncompare = ncompare_cstr;
    this.to_buf = sstr_to_buf;
    this.print = print_sstr;
    this.free = free_sstr;
    return (this);
}