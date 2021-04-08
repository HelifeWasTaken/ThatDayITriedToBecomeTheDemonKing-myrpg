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

    typedef enum layer_object_type {
        LO_WARP,
        LO_NPC,
        LO_UNDEFINED,
        LO_COUNT,
        LO_PNJ = LO_NPC
    } layer_object_type_t;

    typedef struct layer_parser_object {
        const char *match;
        const bool (*parser)(struct layer_object_data *, ig_object_t *);
        const enum layer_object_type type;
    } layer_parser_object_t;

    typedef struct warpzone {
        char *world;
        sfVector2i spawn;
    } warpzone_t;

    typedef union {
        char *message;
        warpzone_t warp;
    } layer_object_value_t;

    struct layer_object_data {
        layer_object_type_t type;
        sfIntRect rect;
        layer_object_value_t object;
    };

    void destroy_layer_object_data(struct layer_object_data *object);
    void destroy_layer_object_warpzone(layer_object_value_t *object);
    void destroy_layer_object_message(layer_object_value_t *object);
    void destroy_layer_object_info(layer_object_info_t *data);

    bool load_warpzone(struct layer_object_data *data, ig_object_t *obj);
    bool load_pnj(struct layer_object_data *data, ig_object_t *obj);
    bool load_layers_object(game_t *game,
        layer_object_manager_t **manager, ig_map_t *map);

    typedef struct layer_object_info {
        struct layer_object_data obj;
        usize_t z;
    } layer_object_info_t;

    INIT_VECTOR(lobject_info, layer_object_info_t, destroy_layer_object_info);
    typedef VECTOR(lobject_info) vector_layer_object_info_t;

#endif