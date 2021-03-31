/*
** EPITECH PROJECT, 2021
** iron$
** File description:
** goat
*/

#ifndef __IRON_GOAT_GRID__H__
    #define  __IRON_GOAT_GRID__H__

    #include <iron_goat/deser.h>

    struct checker_tokens_orientation {
        ig_grid_orientation_t orientation;
        char *match;
    };

    bool iron_goat_grid_parse_orientation(struct json *conf,
                                    struct iron_goat_grid *self);

#endif
