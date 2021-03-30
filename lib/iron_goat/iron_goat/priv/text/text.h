/*
** EPITECH PROJECT, 2021
** iron_goat
** File description:
** text.h
*/

#ifndef _TEXT_H_
    #define _TEXT_H_

    #include <iron_goat/deser.h>

    struct iron_goat_text_halign_parser {
        ig_text_halign_t type;
        char *match;
    };

    struct iron_goat_text_valign_parser {
        ig_text_valign_t type;
        char *match;
    };

    bool iron_goat_load_valign(struct json *conf,
            struct iron_goat_text *self);
    bool iron_goat_text_load_halign(struct json *conf,
            struct iron_goat_text *self);

#endif /* _TEXT_H_ */
