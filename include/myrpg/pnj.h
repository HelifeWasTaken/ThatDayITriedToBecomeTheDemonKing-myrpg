/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** pnj.h
*/

#ifndef PNJ_H
    #define PNJ_H

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
    #include "myrpg/entities.h"
    #include "myrpg/util.h"

    typedef struct pnj_data {
        char *name;
        char *file_path;
        int frame;
        sfVector2u rect_size;
        sfIntRect rect;
        sfSprite *sprite;
        sfVector2f pos;
    } pnj_data_t;

    void destroy_pnj_data(pnj_data_t *my_pnj);

    INIT_VECTOR(pnj_vector, struct pnj_data, destroy_pnj_data);

    bool load_pnj_data_loop(struct json *pnj_conf,
        VECTOR(pnj_vector) **pnj_vector_tab);

    typedef struct pnj {
        entity_t *entity;
        pausable_clock_t *clock;
        VECTOR(pnj_vector) *pnj_vector;
        struct hero *hero;
    } pnj_t;

    bool create_pnj(game_t *game, entity_t *entity);
    void draw_pnj(game_t *game, entity_t *entity);
    void destroy_pnj(game_t *game, entity_t *entity);

#endif
