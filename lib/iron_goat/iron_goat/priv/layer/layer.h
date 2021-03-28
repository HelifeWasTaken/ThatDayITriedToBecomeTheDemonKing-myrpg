/*
** EPITECH PROJECT, 2021
** iron
** File description:
** goat
*/

#ifndef __IRON_GOAT_LAYER__H__
    #define __IRON_GOAT_LAYER__H__

    #include <iron_goat/deser.h>

    struct iron_goat_layer_type_parser {
        ig_layer_type_t type;
        char *match;
    };

    struct iron_goat_layer_encoding_parser {
        ig_layer_encoding_t type;
        char *match;
    };

    struct iron_goat_layer_draworder_parser {
        ig_layer_draworder_t type;
        char *match;
    };

    bool load_iron_goat_layer_chunks(struct json *conf,
            struct iron_goat_layer *self);
    bool load_iron_goat_layer_data(struct json *conf,
        struct iron_goat_layer *self);
    bool load_iron_goat_layer_type(struct json *conf,
            struct iron_goat_layer *self);
    bool load_iron_goat_layer_draworder(struct json *conf,
        struct iron_goat_layer *self);
    bool load_iron_goat_layer_encoding(struct json *conf,
        struct iron_goat_layer *self);
    bool load_iron_goat_map_staggeraxis(struct json *conf,
        struct iron_goat_map *self);

#endif
