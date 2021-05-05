/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** ennemi_json_load.c
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
#include "myrpg/battle.h"

static const struct json_deser_data ENNEMI_DESERT[] = {
    {

    }
};

static bool my_load_ennemi_data(struct json *file, battle_opponent_t *os)
{
    DESER_LOOP(file, os, ENNEMI_DESERT);
}

/* void destroy_ennemi_data(battle_opponent_t *my_ennemi)
{
    FREE(my_ennemi->file_path);
    FREE(my_ennemi->name);
} */

bool load_ennemi_data_loop(struct json *ennemi_conf,
    VECTOR(ennemi_vector) **ennemi_vector_tab)
{
    battle_opponent_t tmp = {0};
    struct json_array *json_arr = NULL;

    if (ennemi_conf->t != JSON_ARR)
        return (false);
    json_arr = ennemi_conf->v.array;
    if ((*ennemi_vector_tab = VECTOR_CREATE(ennemi_vector)) == NULL)
        return (false);
    for (usize_t i = 0; i < json_arr->size; i++) {
        tmp = (battle_opponent_t){0};
        if (my_load_ennemi_data(&json_arr->data[i], &tmp) == false)
            return (false);
        if ((*ennemi_vector_tab)->push_back(ennemi_vector_tab, tmp) == -1)
            return (false);
    }
    return (true);
}

void destroy_ennemies(battle_opponent_t *ennemi)
{
    FREE(ennemi->asset_file);
    FREE(ennemi->name);
}