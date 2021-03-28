/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** eregex
*/

#ifndef __LIBERTY__EREGEX__H__
    #define __LIBERTY__EREGEX__H__

    int regex(char *expr, char const *regexpr, char **startptr, char **endptr);
    int rgx_match(char *expr, char const *regexpr);
    char *rgx_str(char *expr, char const *regexpr);

#endif