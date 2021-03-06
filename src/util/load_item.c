/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** load_item
*/

#include "distract/game.h"
#include "distract/util.h"
#include "distract/window.h"
#include "distract/scene.h"
#include "myrpg/asset.h"
#include "distract/entity.h"
#include "distract/debug.h"
#include "myrpg/entities.h"
#include "myrpg/scenes.h"
#include "myrpg/state.h"
#include "stdlib.h"
#include "myrpg/scenes.h"
#include "myrpg/util.h"
#include "distract/util.h"
#include "iron_goat/deser.h"

static const struct json_deser_data ITEM_JSON[] = {
    {
        .data = ".path",
        .size_data = sizeof(char *),
        .offset = offsetof(item_t, path),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true,
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".type",
        .size_data = sizeof(unsigned int),
        .offset = offsetof(item_t, type),
        .intern = {
            .callback = NULL,
            .woff = false,
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".speed",
        .size_data = sizeof(unsigned int),
        .offset = offsetof(item_t, speed),
        .intern = {
            .callback = NULL,
            .woff = false,
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".shield",
        .size_data = sizeof(unsigned int),
        .offset = offsetof(item_t, shield),
        .intern = {
            .callback = NULL,
            .woff = false,
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".atk",
        .size_data = sizeof(unsigned int),
        .offset = offsetof(item_t, atk),
        .intern = {
            .callback = NULL,
            .woff = false,
        },
        .type = JSON_NUM,
        .opt = false
    }
};

void destroy_item(item_t *item)
{
    for (int index; index != MAX_ITEM; index++) {
        free(item[index].path);
    }
    free(item);
}

bool init_item(struct json *conf, item_t *item)
{
    DESER_LOOP(conf, item, ITEM_JSON);
}

bool load_n_item(game_t *game, usize_t n, json_t *json)
{
    struct json_array *item_arr = json->v.array;
    item_t item = {0};

    if (item_arr->size < n) {
        print_error("error: too many items");
        return (false);
    }
    for (usize_t index = 0; index != n; index++) {
        item = (item_t){0};
        if (init_item(&item_arr->data[index],
            &item) == false) {
            return (false);
        }
        game->item_loaded[index] = item;
    }
    return (true);
}

bool load_items(game_t *game)
{
    json_t conf = {0};

    if (json_parser(&conf, "asset/item/item.json") == false) {
        print_error("could not load item: json missing");
        return (false);
    }
    game->item_loaded = malloc(sizeof(item_t) * MAX_ITEM);
    D_ASSERT(game->item_loaded, NULL, "err", false);
    if (load_n_item(game, MAX_ITEM, &conf) == false) {
        print_error("could not load item:");
        return (false);
    }
    destroy_json(&conf);
    return (true);
}
