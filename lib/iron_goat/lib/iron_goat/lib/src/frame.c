/*
** EPITECH PROJECT, 2021
** frame
** File description:
** frame
*/

#include <iron_goat/deser.h>

static const struct json_deser_data IG_FRAME[] = {
    {
        .data = ".duration",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct iron_goat_frame, duration),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".tileid",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_frame, tileid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    }
};

bool init_iron_goat_frame(struct json *conf, struct iron_goat_frame *self)
{
    DESER_LOOP(conf, self, IG_FRAME);
}