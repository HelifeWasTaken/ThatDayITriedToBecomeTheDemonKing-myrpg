/*
** EPITECH PROJECT, 2021
** grid
** File description:
** loader
*/

#include "grid.h"

static const struct checker_tokens_orientation IG_ORIENTATIONS_TOKENS[] = {
    {GRID_ORTHOGONAL,   "orthogonal"},
    {GRID_ISOMETRIC,    "isometric"}
};

bool iron_goat_grid_parse_orientation(struct json *conf,
                                    struct iron_goat_grid *self)
{
    char *str = conf->v.string;

    if (conf->v.string == NULL) {
        ASSERT("Json", "String grid orientation was null");
        return (false);
    }
    for (size_t i = 0; i < ARRAY_SIZE(IG_ORIENTATIONS_TOKENS); i++) {
        if (estrcmp(str, IG_ORIENTATIONS_TOKENS[i].match) == 0) {
            self->orientation = IG_ORIENTATIONS_TOKENS[i].orientation;
            return (true);
        }
    }
    ASSERT("Json", "String did not seem to havea valid orientation");
    return (false);
}
