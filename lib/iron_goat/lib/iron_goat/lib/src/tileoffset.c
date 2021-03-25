/*
** EPITECH PROJECT, 2021
** tileoffset
** File description:
** off
*/

#include <iron_goat/deser.h>

static const struct json_deser_data IG_TILEOFFSET[] = {
    {
        .data = ".x",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_tileoffset, x),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".y",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_tileoffset, y),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    }
};

bool init_iron_goat_tileoffset(struct json *conf,
                                struct iron_goat_tileoffset *self)
{
    DESER_LOOP(conf, self, IG_TILEOFFSET);
}