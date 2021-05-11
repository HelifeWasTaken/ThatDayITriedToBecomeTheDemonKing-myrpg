/*
** EPITECH PROJECT, 2020
** debug
** File description:
** Source code
*/

#ifndef DISTRACT_DEBUG_H
    #define DISTRACT_DEBUG_H

    void print_error(char *error);

    #define D_ASSERT(var, unexpect, error, retv) \
        if ((var) == (unexpect)) { \
            print_error((error)); \
            return ((retv)); \
        }

#endif //DISTRACT_DEBUG_H
