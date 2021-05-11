/*
** EPITECH PROJECT, 2020
** def
** File description:
** Source code
*/

#ifndef DISTRACT_DEF_H
#define DISTRACT_DEF_H

#define GET_12TH_ARG(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, ...) a12

#define ARGS_COUNT(...) \
    GET_12TH_ARG(0, ## __VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#ifndef UNUSED
    #define UNUSED __attribute__((unused))
#endif

#define IRECT(left, top, width, height) \
    ((sfIntRect) { left, top, width, height })

#define FRECT(left, top, width, height) \
    ((sfFloatRect) { left, top, width, height })

#define VEC2U(x, y) \
    ((sfVector2u) { x, y })

#define VEC2U_X(x) \
    ((sfVector2i) { x, 0 })

#define VEC2U_Y(y) \
    ((sfVector2i) { 0, y })

#define VEC2I(x, y) \
    ((sfVector2i) { x, y })

#define VEC2I_X(x) \
    ((sfVector2i) { x, 0 })

#define VEC2I_Y(y) \
    ((sfVector2i) { 0, y })

#define VEC2F(x, y) \
    ((sfVector2f) { x, y })

#define VEC2F_X(x) \
    ((sfVector2f) { x, 0 })

#define VEC2F_Y(y) \
    ((sfVector2f) { 0, y })

#define CASTVEC2(type, vec1) \
    ((type){vec1.x, vec2.x})

#endif //DISTRACT_DEF_H
