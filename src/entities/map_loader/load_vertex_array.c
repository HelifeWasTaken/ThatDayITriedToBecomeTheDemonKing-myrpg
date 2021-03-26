/*
** EPITECH PROJECT, 2021
** load
** File description:
** load
*/

#include "myrpg/map.h"

#error Need to be lighter and support rotation need to fix v2f too

void load_vertex_data(sfTexture *tileset, map_rect_t *size,
    sfVertexArray **vertex, u64_t *data)
{
    struct tile_id_rot id_rot = {0};
    sfVertexArray_setPrimitiveType(*vertex, sfQuads);
    sfVertexArray_resize(*vertex, size->mapx * size->mapy * 4);

    for (usize_t i = 0; i < size->mapx; ++i) {
        for (usize_t j = 0; j < size->mapy; ++j) {
            id_rot = get_real_tile_id_and_rotation(data[i + j * size->mapx]);
            int tu = id_rot.id % (i64_t)(sfTexture_getSize(tileset).x / size->tilex);
            int tv = id_rot.id / (sfTexture_getSize(tileset).x / size->tilex);
            sfVertex *quad = sfVertexArray_getVertex(*vertex, (i + j * size->mapx) * 4);
            quad[0].position = VEC2F(i * size->tilex, j * size->tiley);
            quad[1].position = VEC2F((i + 1) * size->tilex, j * size->tiley);
            quad[2].position = VEC2F((i + 1) * size->tilex, (j + 1) * size->tiley);
            quad[3].position = VEC2F(i * size->tilex, (j + 1) * size->tiley);

            quad[0].texCoords = VEC2F(tu * size->tilex, tv * size->tiley);
            quad[1].texCoords = VEC2F((tu + 1) * size->tilex, tv * size->tiley);
            quad[2].texCoords = VEC2F((tu + 1) * size->tilex, (tv + 1) * size->tiley);
            quad[3].texCoords = VEC2F(tu * size->tilex, (tv + 1) * size->tiley);
        }
    }
}