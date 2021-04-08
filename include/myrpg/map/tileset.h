/*
** EPITECH PROJECT, 2021
** tileset
** File description:
** layer
*/

#ifndef __LAYER_MYPRG_TILESET__H__
    #define __LAYER_MYPRG_TILESET__H__

    #include <SFML/Graphics.h>
    #include <erty/evector.h>

    enum rotation_tile_map {
        ROT_0,
        ROT_90,
        ROT_180,
        ROT_270
    };

    struct vertex_loader {
        usize_t i;
        usize_t j;
        i64_t tu;
        i64_t tv;
        usize_t mapx;
        usize_t mapy;
        sfVector2u txsize;
        usize_t tilesize;
        usize_t tilesetindex;
        usize_t layerindex;
    };

    struct tileset_parser_args {
        ig_layer_t *layer;
        layer_tileset_info_t *manager;
        VECTOR(ig_tileset) *tileset;
    };

    struct tile_id_rot {
        enum rotation_tile_map rot;
        i64_t id;
    };

    typedef struct layer_tileset_info {
        sfTexture *texture;
        sfVertexArray *vtx;
        usize_t z;
    } layer_tileset_info_t;

    bool load_tileset(game_t *game, ig_map_t *map, tileset_manager_t *manager);
    bool load_vertex_tileset(layer_tileset_info_t *tileset_info,
        usize_t tilesetchose, usize_t i, ig_map_t *map);
    int load_tileset_info(game_t *game,
        layer_tileset_info_t *tileset_info, usize_t i, ig_map_t *map);
    struct tile_id_rot get_real_tile_id_and_rotation(u64_t id);
    void destroy_layer_tileset_info(struct layer_tileset_info *layer);
    bool load_tileset_texture(game_t *game, struct tileset_parser_args *args);

    INIT_VECTOR(ltile_info, struct layer_tileset_info, NULL);
    typedef VECTOR(ltile_info) vector_layer_tileset_t;

    #define MATCH_TILESET(id, tilesetinfo) \
        (((id) >= ((tilesetinfo).firstgid)) && \
            ((id) <= ((tilesetinfo).firstgid + (tilesetinfo).tilecount)))

#endif