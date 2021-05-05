/*
** EPITECH PROJECT, 2021
** object
** File description:
** layer
*/

#ifndef __LAYER_MYPRG_OBJECT__H__
    #define __LAYER_MYPRG_OBJECT__H__

    #include <SFML/Graphics.h>
    #include <erty/evector.h>
    #include "myrpg/map/map.h"

    typedef VECTOR(lobject_info) vector_layer_object_info_t;
    typedef struct layer_object_info layer_object_info_t;

    typedef struct layer_object_manager {
        entity_t *entity;
        vector_layer_object_info_t *layer;
        usize_t actual_layer;
    } layer_object_manager_t;

    bool create_layer_object_manager(game_t *game, entity_t *entity);
    void destroy_layer_object_manager(game_t *game, entity_t *entity);

    typedef struct layer_object {
        layer_object_info_t *obj;
        entity_t *entity;
    } layer_object_t;

    bool create_layer_object(game_t *game, entity_t *entity);
    void destroy_layer_object(game_t *game, entity_t *entity);

    typedef enum layer_object_type {
        LO_WARP,
        LO_NPC,
        LO_UNDEFINED,
        LO_COUNT,
        LO_PNJ = LO_NPC
    } layer_object_type_t;

    typedef struct warpzone_data {
        char *world;
        sfVector2i spawn;
    } warpzone_data_t;


    typedef union {
        struct {
            char **message;
            char *name;
        } pnj;
        warpzone_data_t warp;
    } layer_object_value_t;

    struct layer_object_data {
        layer_object_type_t type;
        sfIntRect rect;
        layer_object_value_t object;
    };

    typedef struct layer_parser_object {
        const char *match;
        bool (*parser)(game_t *, struct layer_object_data *, ig_object_t *);
        const enum layer_object_type type;
    } layer_parser_object_t;

    void destroy_layer_object_message(layer_object_value_t *value);
    void destroy_layer_object_warpzone(layer_object_value_t *value);
    void destroy_layer_object_data(layer_object_info_t *obj);

    bool load_warpzone(game_t *game,
        struct layer_object_data *data, ig_object_t *obj);
    bool load_pnj(game_t *game,
        struct layer_object_data *data, ig_object_t *obj);
    bool load_layers_object(game_t *game,
        struct layer_object_manager **manager, ig_map_t *map);

    struct layer_object_info {
        struct layer_object_data obj;
        usize_t z;
    };

    INIT_VECTOR(lobject_info, layer_object_info_t,
                destroy_layer_object_data);

    typedef struct warpzone {
        entity_t *entity;
        warpzone_data_t warp;
        sfIntRect rect;
        struct hero *hero;
    } warpzone_t;

    bool create_warpzone(game_t *game, entity_t *entity);
    void update_warpzone(game_t *game, entity_t *entity);
    void destroy_warpzone(game_t *game, entity_t *entity);

#endif