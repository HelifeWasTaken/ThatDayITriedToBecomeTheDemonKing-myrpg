/*
** EPITECH PROJECT, 2021
** load
** File description:
** load
*/

#include "myrpg/map.h"

static void load_vertex_quad(map_rect_t *size, sfTexture *tileset,
    struct vertex_loader_data *pos, vertice_data_loader_t *vertice)
{
    struct tile_id_rot id_rot =
        get_real_tile_id_and_rotation(pos->data[pos->i + pos->j * size->mapx]);
    id_rot.id -= vertice->firstgid;
    i64_t tu = id_rot.id % (i64_t)(sfTexture_getSize(tileset).x / size->tilex);
    i64_t tv = id_rot.id / (i64_t)(sfTexture_getSize(tileset).x / size->tilex);
    sfVertex *quad = sfVertexArray_getVertex(vertice->vertex,
        (pos->i + pos->j * size->mapx) * 4);

    quad[0].position = VEC2F(pos->i * size->tilex, pos->j * size->tiley);
    quad[1].position = VEC2F((pos->i + 1) * size->tilex, pos->j * size->tiley);
    quad[2].position = VEC2F((pos->i + 1) *
            size->tilex, (pos->j + 1) * size->tiley);
    quad[3].position = VEC2F(pos->i * size->tilex, (pos->j + 1) * size->tiley);
    if (id_rot.id == -1)
        return;
    set_texture_coords(&(vtx_load_roat_data_t){tu, tv, quad, size, id_rot.rot});
}

void load_vertex_data(sfTexture *tileset, map_rect_t *size,
        vertice_data_loader_t *vertice)
{
    sfVertexArray_setPrimitiveType(vertice->vertex, sfQuads);
    sfVertexArray_resize(vertice->vertex, size->mapx * size->mapy * 4);
    struct vertex_loader_data pos = {0};

    pos.data = vertice->data;
    for (pos.i = 0; pos.i < size->mapx; ++pos.i) {
        for (pos.j = 0; pos.j < size->mapy; ++pos.j) {
            load_vertex_quad(size, tileset, &pos, vertice);
        }
    }
}