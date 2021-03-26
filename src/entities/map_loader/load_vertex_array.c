/*
** EPITECH PROJECT, 2021
** load
** File description:
** load
*/

#include "myrpg/map.h"

static void load_vertex_quad(map_rect_t *size, sfVertexArray **vertex,
    struct vertex_loader_data *pos, sfTexture *tileset)
{
    struct tile_id_rot id_rot =
        get_real_tile_id_and_rotation(pos->data[pos->y + pos->x * size->mapx]);
    i64_t tu = id_rot.id % (i64_t)(sfTexture_getSize(tileset).x / size->tilex);
    i64_t tv = id_rot.id / (sfTexture_getSize(tileset).x / size->tilex);
    sfVertex *quad = sfVertexArray_getVertex(*vertex,
        (pos->y + pos->x * size->mapx) * 4);

    quad[0].position = VEC2F(pos->y * size->tilex, pos->x * size->tiley);
    quad[1].position = VEC2F((pos->y + 1) * size->tilex, pos->x * size->tiley);
    quad[2].position = VEC2F((pos->y + 1) * size->tilex,
        (pos->x + 1) * size->tiley);
    quad[3].position = VEC2F(pos->y * size->tilex, (pos->x + 1) * size->tiley);
    set_texture_coords(&(vtx_load_roat_data_t){
        .quad = quad,
        .rotation = id_rot.rot,
        .size = size,
        .tu = tu,
        .tv = tv
    });
}

void load_vertex_data(sfTexture *tileset, map_rect_t *size,
    sfVertexArray **vertex, u64_t *data)
{
    sfVertexArray_setPrimitiveType(*vertex, sfQuads);
    sfVertexArray_resize(*vertex, size->mapx * size->mapy * 4);
    struct vertex_loader_data pos = {0};

    pos.data = data;
    for (pos.x = 0; pos.x < size->mapx; ++pos.x) {
        for (pos.y = 0; pos.y < size->mapy; ++pos.y) {
            load_vertex_quad(size, vertex, &pos, tileset);
        }
    }
}