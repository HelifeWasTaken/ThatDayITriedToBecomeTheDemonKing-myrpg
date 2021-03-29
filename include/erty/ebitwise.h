/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** ebitwise
*/

#ifndef __LIBERTY__EBITWISE__H__
    #define __LIBERTY__EBITWISE__H__

    //   _____ _     _ _            _
    //  |  ___| |   (_) |          (_)
    //  | |__ | |__  _| |___      ___ ___  ___
    //  |  __|| '_ \| | __\ \ /\ / / / __|/ _ |
    //  | |___| |_) | | |_ \ V  V /| \__ \  __/
    //  \____/|_.__/|_|\__| \_/\_/ |_|___/\___|
    //

    #define GET_BIT(var, bit) \
        (var & 1 << bit) >> bit

    #define SET_BIT(var, boolean, bit) \
        ((boolean) ? \
        ((GET_BIT(var, bit) == 0) ? var | (1 << bit) : var) : \
        ((GET_BIT(var, bit) == 1) ? var ^ (1 << bit) : var))

    #define LS_BIT(byte) \
        ((byte) ^ ((byte) - 1) & (byte))

#endif /* !__LIBERTY__BITWISE__H__ */