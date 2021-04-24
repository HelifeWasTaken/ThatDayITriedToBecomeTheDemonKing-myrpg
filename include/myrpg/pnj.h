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
    #include "myrpg/util.h"

    typedef struct pnj {
        char *name;
        char *file_path;
        int frame;
        sfIntRect rect;
    } pnj_t;

    void destroy_pnj(pnj_t *my_pnj);

    INIT_VECTOR(pnj_vector, struct pnj, destroy_pnj);

    bool load_pnj_loop(struct json *pnj_conf,
        VECTOR(pnj_vector) **pnj_vector_tab);

#endif