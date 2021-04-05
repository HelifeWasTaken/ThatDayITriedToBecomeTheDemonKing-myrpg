/*
** EPITECH PROJECT, 2020
** main
** File description:
** Source code
*/

//#include "my/io.h"
#include <iron_goat/deser.h>
#include "erty/eprintf.h"
#include "myrpg/game.h"
#include "distract/window.h"
#include "distract/graphics.h"
#include "distract/resources.h"
#include "distract/game.h"
#include "myrpg/map.h"
#include <stdio.h>
#include <SFML/Graphics.h>
#include <iron_goat/deser.h>
#include "myrpg/util.h"

/*
struct pnj_data {
    char *name;
    char **message;
    u64_t x;
    u64_t y;
};

struct pnj {
    VECTOR(pnjv) *pnjs;
};

INIT_VECTOR(pnjv, struct pnj_data, NULL);

static bool load_pnj_message(struct json *conf,
    struct pnj_data *self)
{
    struct json_array *data = conf->v.array;

    for (size_t i = 0; i < data->size; i++) {
        if (data->data[i].t != JSON_STR)
            return (false);
        if ((self->message = eappend_tab(&self->message,
            data->data[i].v.string)) == NULL)
            return (false);
    }
    return (true);
}

static const struct json_deser_data PNJ_DATA_LOADER[] = {
    {
        .data = ".name",
        .size_data = sizeof(char *),
        .offset = offsetof(struct pnj_data, name),
        .intern = {
            .callback = iron_goat_get_string,
            .woff = true
        },
        .type = JSON_STR,
        .opt = false
    },
    {
        .data = ".message",
        .size_data = sizeof(char **),
        .offsetof = offsetof(struct pnj_data, message),
        .intern = {
            .callback = load_pnj_message,
            .woff = false
        },
        .type = JSON_ARR,
        .opt  = false
    },
    {
        .data = ".x",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct pnj_data, x),
        .intern = {
            .callback = NULL,
            .opt = false,
        },
        .type = JSON_NUM,
        .opt = false
    },
    {
        .data = ".y",
        .size_data = sizeof(u64_t),
        .offset = offsetof(struct pnj_data, y),
        .intern = {

        },
        .type = JSON_NUM,
        .opt = false
    }
};

static bool init_pnj_data(struct json *conf,
    struct pnj_data *self)
{
    DESER_LOOP(conf, self, PNJ_DATA_LOADER);
}

static bool load_pnj_vector(struct json *conf,
    struct pnj *self)
{
    struct json_array *data = conf->v.array;
    struct pnj_data pnj = {0};

    if ((self->pnjs = VECTOR_CREATE(pnjv)) == NULL)
        return (false);
    for (size_t i = 0; i < data->size; i++) {
        pnj = (struct pnj_data){0};
        if (data->data[i].t != JSON_OBJ) {
            ASSERT("PnjData", "Pnj data was not an object");
            return (false);
        }
        if (init_pnj_data(&data->data[i], &pnj) == false)
            return (false);
        if (self->pnjs->push_back(&self->pnjs, pnj) == -1)
            return (false);
    }
    return (true);
}

static const struct json_deser_data PNJ_LOADER[] = {
    {
        .data = ".pnjdata",
        .size_data = sizeof(VECTOR(pnjv) *),
        .offset = offsetof(struct pnj, pnjs),
        .intern = {
            .callback = load_pnj_vector,
            .woff = false
        },
        .type = JSON_ARR,
        .opt = false
    }
};

bool init_pnjs(struct json *conf, struct pnj *self)
{
    DESER_LOOP(conf, self, PNJ_LOADER);
}
*/

#include "myrpg/mapdata.h"
int main(void)
{
    eprintf("in main");
    return (load_game());
}
