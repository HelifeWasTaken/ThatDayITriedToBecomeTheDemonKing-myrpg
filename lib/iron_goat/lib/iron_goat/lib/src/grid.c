/*
** EPITECH PROJECT, 2021
** grid
** File description:
** grid
*/

#include <iron_goat/deser.h>
#include "priv/grid/grid.h"

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
