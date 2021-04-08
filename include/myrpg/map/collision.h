/*
** EPITECH PROJECT, 2021
** object
** File description:
** layer
*/

#ifndef __LAYER_MYPRG_COLLISION__H__
    #define __LAYER_MYPRG_COLLISION__H__

    #include <SFML/Graphics.h>
    #include "myrpg/map/tileset.h"

    typedef struct layer_collision_info {
        bool *map;
        usize_t size;
        sfVertexArray *vtx;
        sfVector2u mapsize;
        usize_t z;
    } layer_collision_data_t;

    bool load_collision_layer(game_t *game, ig_map_t *map,
        layer_collision_data_t *data);

#endif