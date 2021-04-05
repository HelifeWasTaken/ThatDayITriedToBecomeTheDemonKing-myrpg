/*
** EPITECH PROJECT, 2020
** warp
** File description:
** Entity
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "iron_goat/deser.h"
#include "myrpg/mapdata.h"
#include "myrpg/util.h"
#include "distract/util.h"

static const struct json_deser_data WARP_DATA_DES[] = {
    {
        .data = ".warpzone",
        .size_data = sizeof(sfIntRect),
        .offset = offsetof(struct warp_data, warpzone),
        .intern = {
            .callback = deser_irect,
            .woff = true
        },
        .type = JSON_OBJ,
        .opt = false
    },
    {
        .data = ".warploader",
        .size_data = sizeof(char *),
        .offset = offsetof(struct warp_data, warploader),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    }
};

static bool init_warp_data(struct json *conf, struct warp_data *wdata)
{
    DESER_LOOP(conf, wdata, WARP_DATA_DES);
}

static bool load_warp_vector(struct json *conf, warp_t **warp)
{
    struct warp_data tmp = {0};
    struct json_array *arr = conf->v.array;

    if (((*warp)->warp = VECTOR_CREATE(wrp)) == NULL)
        return (false);
    for (usize_t i = 0; i < arr->size; i++) {
        tmp = (struct warp_data){0};
        if (arr->data[i].t != JSON_OBJ) {
            ASSERT("WarpLoader", "Member of array is not an object");
            return (false);
        }
        if (init_warp_data(&arr->data[i], &tmp) == false)
            return (false);
        if ((*warp)->warp->push_back(&(*warp)->warp, tmp) == -1)
            return (false);
    }
    return (true);
}

bool create_warp(game_t *game UNUSED, entity_t *entity)
{
    warp_t *warp = dcalloc(sizeof(warp_t), 1);
    json_t conf = {0};

    D_ASSERT(warp, NULL, "Failed to init warp", false)
    D_ASSERT(json_parser(&conf,
        MAP_FILES[game->scene->world_id].m_files.warpfile),
        false, "Failed to parse warpfile", false);
    warp->entity = entity;
    entity->instance = warp;
    if (load_warp_vector(&conf, &warp) == false) {
        destroy_json(&conf);
        return (false);
    }
    destroy_json(&conf);
    return (true);
}

void destroy_warp(game_t *game UNUSED, entity_t *entity)
{
    warp_t *warp = entity->instance;

    if (warp->warp)
        warp->warp->clear(&warp->warp);
    free(warp);
}