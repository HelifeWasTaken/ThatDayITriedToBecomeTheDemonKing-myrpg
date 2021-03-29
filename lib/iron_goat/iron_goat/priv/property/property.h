/*
** EPITECH PROJECT, 2021
** load
** File description:
** tie
*/

#ifndef __IRON_GOAT_PROPERTY_H__
    #define __IRON_GOAT_PROPERTY_H__

    #include <iron_goat/deser.h>

    struct iron_goat_get_property_parser {
        enum json_type type;
        size_t size_arg;
        bool (*callback)();
        ig_property_type_t prop;
    };

    bool iron_goat_get_property(struct json *conf,
            struct iron_goat_property *self);
#endif
