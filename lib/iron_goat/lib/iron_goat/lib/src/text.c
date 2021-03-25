/*
** EPITECH PROJECT, 2021
** text
** File description:
** text
*/

#include <iron_goat/deser.h>
#include "priv/text/text.h"

void destroy_iron_goat_text(struct iron_goat_text *self)
{
    FREE(self->fontfamily);
    FREE(self->text);
}

static const struct json_deser_data IG_TEXT[] = {
    {
        .data = ".bold",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_text, bold),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    },
    {
        .data = ".color",
        .size_data = sizeof(u32_t),
        .offset = offsetof(struct iron_goat_text, color),
        .intern = {
            .callback = iron_goat_get_color,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".fontfamily",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_text, fontfamily),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".halign",
        .size_data = sizeof(sizeof(ig_text_halign_t)),
        .offset = offsetof(struct iron_goat_text, halign),
        .intern = {
            .callback = iron_goat_text_load_halign,
            .woff = false
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".italic",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_text, italic),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    },
    {
        .data = ".kerning",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_text, kerning),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    },
    {
        .data = ".pixelsize",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_text, pixelsize),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".strikeout",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_text, strikeout),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    },
    {
        .data = ".text",
        .size_data = sizeof(char *),
        .offset = offsetof(struct iron_goat_text, text),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".underline",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_text, underline),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    },
    {
        .data = ".valign",
        .size_data = sizeof(ig_text_valign_t),
        .offset = offsetof(struct iron_goat_text, valign),
        .intern = {
            .callback = iron_goat_load_valign,
            .woff = false
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".wrap",
        .size_data = sizeof(bool),
        .offset = offsetof(struct iron_goat_text, wrap),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    }
};

bool init_iron_goat_text(struct json *conf, struct iron_goat_text *self)
{
    DESER_LOOP(conf, self, IG_TEXT);
}
