/*
** EPITECH PROJECT, 2021
** iron$
** File description:
** goat
*/

#ifndef __IRON_GOAT__MAP__H__
    #define __IRON_GOAT__MAP__H__

    #include <iron_goat/deser.h>

    struct iron_goat_orientation_parser {
        ig_map_orient_t type;
        char *match;
    };

    struct iron_goat_renderorder_parser {
        ig_map_renderorder_t type;
        char *match;
    };

    struct iron_goat_staggeraxis_parser {
        ig_map_staggeraxis_t type;
        char *match;
    };

    struct iron_goat_staggerindex_parser {
        ig_map_staggerindex_t type;
        char *match;
    };

    bool load_iron_goat_map_renderorder(struct json *conf,
        struct iron_goat_map *self);
    bool load_iron_goat_map_orientation(struct json *conf,
        struct iron_goat_map *self);
    bool load_iron_goat_map_staggeraxis(struct json *conf,
        struct iron_goat_map *self);
    bool load_iron_goat_map_staggerindex(struct json *conf,
        struct iron_goat_map *self);

#endif
