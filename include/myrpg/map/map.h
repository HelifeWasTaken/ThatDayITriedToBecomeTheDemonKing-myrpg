/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/


#ifndef __MY_RPG__MAP__H__
    #define __MY_RPG__MAP__H__

    #include <iron_goat/deser.h>
    #include "myrpg/map/collision.h"
    #include "myrpg/map/object.h"
    #include "myrpg/map/tileset.h"
    #include "distract/entity.h"

    bool load_map_from_file(game_t *game, ig_map_t *map_conf);

    typedef struct layer_manager {
        struct layer_object_manager *objects;
        struct layer_tileset_manager *tilesets;
        struct layer_collision *collision;
        sfVector2u mapsize;
        unsigned int tilesize;
    } layer_manager_t;

    #define GET_REAL_POSITION_XY(v, xoff, yoff, tsize) \
        (sfVector2u){(((v).x) + (xoff)) / tsize, (((v).y) + (yoff)) / tsize}

    #define GET_POS_MAP(v, mw, map) \
        map[(i64_t)((v).x + (v).y * (mw))]
#endif
