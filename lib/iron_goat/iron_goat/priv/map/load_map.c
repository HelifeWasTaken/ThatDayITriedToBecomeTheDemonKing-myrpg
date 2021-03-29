/*
** EPITECH PROJECT, 2021
** load
** File description:
** goat
*/

#include "map.h"

static const struct iron_goat_renderorder_parser IG_RORD_TOKENS_PARSER[] = {
    {MAP_RIGHT_DOWN, "right-down"},
    {MAP_RIGHT_UP, "right-up"},
    {MAP_LEFT_DOWN, "left-down"},
    {MAP_LEFT_UP, "left-up"}
};

static const struct iron_goat_orientation_parser IG_ORI_TOKENS_PARSER[] = {
    {MAP_ORTHOGONAL, "orthogonal"},
    {MAP_ISOMETRIC, "isometric"},
    {MAP_STAGGERED, "staggered"},
    {MAP_HEXAGONAL, "hexagonal"}
};

static const struct iron_goat_staggeraxis_parser IG_STAX_TOKENS_PARSER[] = {
    {MAP_STAG_X, "x"},
    {MAP_STAG_Y, "y"}
};

static const struct iron_goat_staggerindex_parser IG_STAI_TOKENS_PARSER[] = {
    {MAP_STAG_ODD, "odd"},
    {MAP_STAG_EVEN, "even"}
};

bool load_iron_goat_map_orientation(struct json *conf,
        struct iron_goat_map *self)
{
    char *s = conf->v.string;

    for (size_t i = 0; i < ARRAY_SIZE(IG_ORI_TOKENS_PARSER); i++) {
        if (estrcmp(s, IG_ORI_TOKENS_PARSER[i].match) == 0) {
            self->orientation = IG_ORI_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Orientation has a invalid or corrupted value");
    return (false);
}

bool load_iron_goat_map_renderorder(struct json *conf,
    struct iron_goat_map *self)
{
    char *s = conf->v.string;

    for (size_t i = 0; i < ARRAY_SIZE(IG_RORD_TOKENS_PARSER); i++) {
        if (estrcmp(s, IG_RORD_TOKENS_PARSER[i].match) == 0) {
            self->renderorder = IG_RORD_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Renderorder has a invalid or corrupted value");
    return (false);
}

bool load_iron_goat_map_staggeraxis(struct json *conf,
    struct iron_goat_map *self)
{
    char *s = conf->v.string;

    for (size_t i = 0; i < ARRAY_SIZE(IG_STAX_TOKENS_PARSER); i++) {
        if (estrcmp(s, IG_STAX_TOKENS_PARSER[i].match) == 0) {
            self->staggeraxis = IG_STAX_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "StaggerAxis has a invalid or corrupted value");
    return (false);
}

bool load_iron_goat_map_staggerindex(struct json *conf,
    struct iron_goat_map *self)
{
    char *s = conf->v.string;

    for (size_t i = 0; i < ARRAY_SIZE(IG_STAI_TOKENS_PARSER); i++) {
        if (estrcmp(s, IG_STAI_TOKENS_PARSER[i].match) == 0) {
            self->staggerindex = IG_STAI_TOKENS_PARSER[i].type;
            return (true);
        }
    }
    ASSERT("Json", "Staggerindex has a invalid or corrupted value");
    return (false);
}
