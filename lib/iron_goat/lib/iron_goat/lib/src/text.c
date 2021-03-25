/*
** EPITECH PROJECT, 2021
** text
** File description:
** text
*/

#include <iron_goat/deser.h>

void destroy_iron_goat_text(struct iron_goat_text *self)
{
    FREE(self->fontfamily);
    FREE(self->text);
}

struct iron_goat_text_halign_parser {
    ig_text_halign_t type;
    char *match;
};

static const struct iron_goat_text_halign_parser IG_HALIGN_TOKENS_PARSER[] = {
    {HALIGN_CENTER, "center"},
    {HALIGN_RIGHT, "right"},
    {HALIGN_JUSTIFY, "justify"},
    {HALIGN_LEFT, "left"}
};

static bool iron_goat_text_load_halign(struct json *conf,
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

struct iron_goat_text_valign_parser {
    ig_text_valign_t type;
    char *match;
};

static const struct iron_goat_text_valign_parser IG_VALIGN_TOKENS_PARSER[] = {
    {VALIGN_CENTER, "center"},
    {VALIGN_BOTTOM, "bottom"},
    {VALIGN_TOP, "top"},
};

static bool iron_goat_load_valign(struct json *conf,
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