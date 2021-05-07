/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** pnj_loader.c
*/

#include <iron_goat/deser.h>
#include "myrpg/battle.h"
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

static const struct json_deser_data BOSS_DESER[] = {
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(boss_data_t, name),
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
        .offset = offsetof(boss_data_t, file_path),
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
        .offset = offsetof(boss_data_t, frame),
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
        .offset = offsetof(boss_data_t, rect),
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
        .offset = offsetof(boss_data_t, pos),
        .intern = {
            .callback = deser_vector2f,
            .woff = true,
        },
        .type = JSON_OBJ,
        .opt = false
    },
    {
        .data = ".boss_id",
        .size_data = sizeof(int),
        .offset = offsetof(boss_data_t, boss_id),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".hp",
        .size_data = sizeof(int),
        .offset = offsetof(boss_data_t, hp),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".mana",
        .size_data = sizeof(int),
        .offset = offsetof(boss_data_t, mana),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".scale",
        .size_data = sizeof(sfVector2f),
        .offset = offsetof(boss_data_t, scale),
        .intern = {
            .callback = deser_vector2f,
            .woff = true
        },
        .type = JSON_OBJ,
        .opt = false
    },
    {
        .data = ".pos_offset",
        .size_data = sizeof(sfVector2f),
        .offset = offsetof(boss_data_t, pos_offset),
        .intern = {
            .callback = deser_vector2f,
            .woff = true
        },
        .type = JSON_OBJ,
        .opt = false
    },
    {
        .data = ".trigger_battle",
        .size_data = sizeof(bool),
        .offset = offsetof(boss_data_t, trigger_battle),
        .intern = {
            .callback = NULL,
            .woff = false
        },
        .type = JSON_BOOL,
        .opt = false
    }
};

static bool my_load_boss_data(struct json *file, boss_data_t *os)
{
    DESER_LOOP(file, os, BOSS_DESER);
}

void destroy_boss_data(boss_data_t *my_pnj)
{
    FREE(my_pnj->file_path);
    FREE(my_pnj->name);
}

bool load_boss_data_loop(struct json *pnj_conf,
    VECTOR(boss_vector) **pnj_vector_tab)
{
    boss_data_t tmp = {0};
    struct json_array *json_arr = NULL;

    if (pnj_conf->t != JSON_ARR)
        return (false);
    json_arr = pnj_conf->v.array;
    if ((*pnj_vector_tab = VECTOR_CREATE(boss_vector)) == NULL)
        return (false);
    for (usize_t i = 0; i < json_arr->size; i++) {
        tmp = (boss_data_t){0};
        if (my_load_boss_data(&json_arr->data[i], &tmp) == false)
            return (false);
        if ((*pnj_vector_tab)->push_back(pnj_vector_tab, tmp) == -1)
            return (false);
    }
    return (true);
}
