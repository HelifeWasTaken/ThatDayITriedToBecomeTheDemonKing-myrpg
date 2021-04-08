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
        layer_object_manager_t *objects;
        layer_tileset_manager_t *tilesets;
        layer_collision_t *collision;
        sfVector2u mapsize;
    } layer_manager_t;

    typedef struct layer_object_manager {
        entity_t *entity;
        vector_layer_object_info_t *layer;
        usize_t actual_layer;
    } layer_object_manager_t;

    bool create_layer_object_manager(game_t *game, entity_t *entity);
    void draw_layer_object_manager(game_t *game, entity_t *entity);
    void destroy_layer_object_manager(game_t *game, entity_t *entity);

    typedef struct layer_object {
        layer_object_info_t *obj;
        entity_t *entity;
    } layer_object_t;

    bool create_layer_object(game_t *game, entity_t *entity);
    void destroy_layer_object(game_t *game, entity_t *entity);

    typedef struct layer_tileset {
        entity_t *entity;
        vector_layer_tileset_t *tileset;
        usize_t actual_layer;
    } layer_tileset_manager_t;
    typedef layer_tileset_manager_t tileset_manager_t;

    bool create_layer_manager_tileset(game_t *game, entity_t *entity);
    void destroy_layer_manager_tileset(game_t *game, entity_t *entity);

    typedef struct tileset_layer {
        layer_tileset_info_t layer;
        entity_t *entity;
    } layer_tileset_t;

    bool create_tileset_layer(game_t *game, entity_t *entity);
    void draw_tileset_layer(game_t *game, entity_t *entity);
    void destroy_tileset_layer(game_t *game, entity_t *entity);

    typedef struct layer_collision {
        entity_t *entity;
        layer_collision_data_t data;
    } layer_collision_t;

    bool create_layer_collision(game_t *game, entity_t *entity);
    void draw_layer_collision(game_t *game, entity_t *entity);
    void destroy_layer_collision(game_t *game, entity_t *entity);

    bool load_map_from_file(game_t *game, ig_map_t *map_conf);

#endif