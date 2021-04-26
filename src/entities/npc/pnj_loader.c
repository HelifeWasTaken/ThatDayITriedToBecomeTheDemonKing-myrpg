/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** pnj_loader.c
*/

#include <iron_goat/deser.h>
#include "myrpg/game.h"
#include "distract/window.h"
#include "distract/graphics.h"
#include "distract/resources.h"
#include "distract/game.h"
#include "myrpg/map/map.h"
#include <stdio.h>
#include <SFML/Graphics.h>
#include <iron_goat/deser.h>
#include "myrpg/util.h"
#include "myrpg/pnj.h"

static const struct json_deser_data PNJ_DESER[] = {
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(pnj_data_t, name),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false,
    },
    {
        .data = ".file_path",
        .size_data = sizeof(char *),
        .offset = offsetof(pnj_data_t, file_path),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false,
    },
    {
        .data = ".frame",
        .size_data = sizeof(int),
        .offset = offsetof(pnj_data_t, frame),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".rect",
        .size_data = sizeof(sfIntRect),
        .offset = offsetof(pnj_data_t, rect),
        .intern = {
            .callback = deser_irect,
            .woff = true
        },
        .type = JSON_OBJ,
        .opt = false
    },
    {
        .data = ".pos",
        .size_data = sizeof(sfVector2f),
        .offset = offsetof(pnj_data_t, pos),
        .intern = {
            .callback = deser_vector2f,
            .woff = true,
        },
        .type = JSON_OBJ,
        .opt = false
    }
};

static bool my_load_pnj_data(struct json *file, pnj_data_t *os)
{
    DESER_LOOP(file, os, PNJ_DESER);
}

void destroy_pnj_data(pnj_data_t *my_pnj)
{
    FREE(my_pnj->file_path);
    FREE(my_pnj->name);
}

bool load_pnj_data_loop(struct json *pnj_conf,
    VECTOR(pnj_vector) **pnj_vector_tab)
{
    pnj_data_t tmp = {0};
    struct json_array *json_arr = NULL;

    if (pnj_conf->t != JSON_ARR)
        return (false);
    json_arr = pnj_conf->v.array;
    if ((*pnj_vector_tab = VECTOR_CREATE(pnj_vector)) == NULL)
        return (false);
    for (usize_t i = 0; i < json_arr->size; i++) {
        tmp = (pnj_data_t){0};
        if (my_load_pnj_data(&json_arr->data[i], &tmp) == false)
            return (false);
        if ((*pnj_vector_tab)->push_back(pnj_vector_tab, tmp) == -1)
            return (false);
    }
    return (true);
}
