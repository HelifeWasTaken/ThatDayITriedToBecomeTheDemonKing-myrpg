/*
** EPITECH PROJECT, 2021
** wangtile
** File description:
** wang
*/

#include <iron_goat/deser.h>

static bool load_iron_goat_wangtile_wangid(struct json *conf,
    struct iron_goat_wangtile *self)
{
    struct json_array *data = conf->v.array;

    if (data->size != 8) {
        ASSERT("Json", "wangid is corrupted");
        return (false);
    }
    for (size_t i = 0; i < data->size; i++) {
        self->wangid[i] = data->data[i].v.number;
    }
    return (true);
}

static const struct json_deser_data IG_WANGTILE[] = {
    {
        .data = ".tileid",
        .size_data = sizeof(i64_t),
        .offset = offsetof(struct iron_goat_wangtile, tileid),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".wangid",
        .size_data = sizeof(u8_t) * 8,
        .offset = offsetof(struct iron_goat_wangtile, wangid),
        .intern = {
            .callback = load_iron_goat_wangtile_wangid,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    },
};

bool init_iron_goat_wangtile(struct json *conf,
    struct iron_goat_wangtile *self)
{
    DESER_LOOP(conf, self, IG_WANGTILE);
}