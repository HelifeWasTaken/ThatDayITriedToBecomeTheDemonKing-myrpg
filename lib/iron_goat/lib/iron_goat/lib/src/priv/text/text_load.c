/*
** EPITECH PROJECT, 2021
** iron_goat
** File description:
** text_load.c
*/

#include "text.h"

static const struct iron_goat_text_halign_parser IG_HALIGN_TOKENS_PARSER[] = {
    {HALIGN_CENTER, "center"},
    {HALIGN_RIGHT, "right"},
    {HALIGN_JUSTIFY, "justify"},
    {HALIGN_LEFT, "left"}
};

static const struct iron_goat_text_valign_parser IG_VALIGN_TOKENS_PARSER[] = {
    {VALIGN_CENTER, "center"},
    {VALIGN_BOTTOM, "bottom"},
    {VALIGN_TOP, "top"},
};

bool iron_goat_load_valign(struct json *conf,
        struct iron_goat_text *self)
{
    for (size_t i = 0; i < ARRAY_SIZE(IG_HALIGN_TOKENS_PARSER); i++) {
        if (estrcmp(conf->v.string, IG_VALIGN_TOKENS_PARSER[i].match) == 0) {
            self->valign = IG_VALIGN_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Tokens parser valign unrecognized token");
    return (false);
}

bool iron_goat_text_load_halign(struct json *conf,
        struct iron_goat_text *self)
{
    for (size_t i = 0; i < ARRAY_SIZE(IG_HALIGN_TOKENS_PARSER); i++) {
        if (estrcmp(conf->v.string, IG_HALIGN_TOKENS_PARSER[i].match) == 0) {
            self->halign = IG_HALIGN_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Tokens parser halign unrecognized token");
    return (false);
}

