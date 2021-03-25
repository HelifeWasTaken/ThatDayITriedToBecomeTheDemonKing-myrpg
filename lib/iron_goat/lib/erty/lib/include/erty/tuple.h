/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** tuple
*/

#ifndef __LIBERTY__TUPLE__H__
    #define __LIBERTY__TUPLE__H__

    #define TUPLE(name) \
        struct liberty_templated_tuple_##name

    #define SET_TUPLE(name, key, value) \
        TUPLE(name){key, name}

    #define INIT_TUPLE(name, type) \
        TUPLE(name) { \
            char *key; \
            type data; \
        };

#endif
