/*
** EPITECH PROJECT, 2021
** grid
** File description:
** grid
*/

#include <iron_goat/deser.h>

struct checker_tokens_orientation {
    ig_grid_orientation_t orientation;
    char *match;
};

static const struct checker_tokens_orientation IG_ORIENTATIONS_TOKENS[] = {
    {GRID_ORTHOGONAL,   "orthogonal"},
    {GRID_ISOMETRIC,    "isometric"}
};

static bool iron_goat_grid_parse_orientation(struct json *conf,
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

static const struct json_deser_data IG_GRID[] = {
    {
        .data = ".height",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_grid, height),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".orientation",
        .size_data = sizeof(ig_grid_orientation_t),
        .offset  = offsetof(struct iron_goat_grid, orientation),
        .intern = { 
            .callback = iron_goat_grid_parse_orientation,
            .woff = false
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".width",
        .size_data = sizeof(u64_t),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .offset = offsetof(struct iron_goat_grid, width),
        .type = JSON_NUM,
        .opt = false
    }
};

bool init_iron_goat_grid(struct json *conf, struct iron_goat_grid *self)
{
    DESER_LOOP(conf, self, IG_GRID);
}