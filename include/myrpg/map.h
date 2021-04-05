/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/


#ifndef __MY_RPG__MAP__H__
    #define __MY_RPG__MAP__H__

    #include <iron_goat/deser.h>
    #include <SFML/Graphics.h>
    #include "distract/game.h"

    struct vector_vertex_array_data {
        usize_t tileset;
        sfVertexArray *vertex;
    };

    struct vector_vertex_array {
        struct vector_vertex_array_data *vec;
        size_t size;
    };

    struct vector_texture {
        sfTexture **tileset;
        size_t size;
    };

    struct vector_collision {
        bool *layer;
        u8_t tilesize;
        size_t size;
    };

    typedef struct vertex_array_map {
        struct vector_vertex_array v_vertex;
        struct vector_texture v_texture;
        sfVector2u map_size;
        sfVector2u tile_size;
        struct vector_collision v_collision;
        sfRenderStates states;
    } vertex_map_t;

    typedef struct map_rect {
        uint64_t mapx;
        uint64_t mapy;
        uint64_t tilex;
        uint64_t tiley;
    } map_rect_t;

    enum rotation_tile_map {
        ROT_0,
        ROT_90,
        ROT_180,
        ROT_270
    };

    struct tile_id_rot {
        enum rotation_tile_map rot;
        i64_t id;
    };

    struct vertex_loader_data {
        usize_t i;
        usize_t j;
        u64_t *data;
    };

    typedef struct vertex_loader_rotation_data {
        i64_t tu;
        i64_t tv;
        sfVertex *quad;
        map_rect_t *size;
        enum rotation_tile_map rotation;
    } vtx_load_roat_data_t;

    struct vertex_funcpointer_rotation_set {
        void (*fun)(vtx_load_roat_data_t *);
    };

    typedef struct {
        sfVertexArray *vertex;
        u64_t *data;
        u64_t firstgid;
    } vertice_data_loader_t;

    struct tile_id_rot get_real_tile_id_and_rotation(u64_t id);

    #define DEFAULT_RENDERSTATE(texturedata) \
        (sfRenderStates){ \
            .blendMode = sfBlendAlpha, \
            .shader = NULL, \
            .transform = sfTransform_Identity, \
            .texture = texturedata \
        }

    #define MAP_RECT(map, textures, tilesetv) \
        (map_rect_t){map->width, map->height, \
            map->tilesets->data[tilesetv].tilewidth, \
            map->tilesets->data[tilesetv].tileheight}

    bool load_vertex_array_map(game_t *game, ig_map_t *map,
        struct vertex_array_map *self, char const *pathfolder);

    // Integrity checks
    bool load_vertex_array_map_get_tileset(ig_map_t *map,
        struct iron_goat_layer *layer, usize_t *tileset);
    bool check_tileset_and_data(struct iron_goat_layer *layer,
        struct iron_goat_tileset *tileset);

    void load_vertex_data(sfTexture *tileset, map_rect_t *size,
            vertice_data_loader_t *vertice);
    void set_texture_coords(struct vertex_loader_rotation_data *data);

    void draw_map_layers_from_to(sfRenderWindow *window,
        struct vertex_array_map *self, size_t start, size_t end);
    void draw_all_vertex_map(sfRenderWindow *window,
        struct vertex_array_map *self);
    void draw_map_layer(sfRenderWindow *window,
        struct vertex_array_map *self, size_t n);
    void draw_map_layer(sfRenderWindow *window,
        struct vertex_array_map *self, size_t n);

    #define GET_REAL_POSITION_XY(v, xoff, yoff) \
        (sfVector2u){(((v).x) + (xoff)) / 16, (((v).y) + (yoff)) / 16}

    #define GET_POS_MAP(v, mw, map) \
        map[(i64_t)((v).x + (v).y * (mw))]

#endif
