/*
** EPITECH PROJECT, 2021
** load
** File description:
** vertex
*/

#include "myrpg/map/map.h"

static void set_full_alpha(sfVertex *vertex)
{
    sfColor alpha = sfColor_fromRGBA(0, 0, 0, 0);

    vertex[0].color = alpha;
    vertex[1].color = alpha;
    vertex[2].color = alpha;
    vertex[3].color = alpha;
}

static bool load_vertex_quad(layer_tileset_info_t *tileset_info,
    struct vertex_loader *ldata, ig_map_t *map)
{
    struct tile_id_rot idrot = get_real_tile_id_and_rotation(
        map->layers->data[ldata->layerindex].data.data[
        ldata->i + ldata->j * ldata->mapx]);
    sfVertex *quad = sfVertexArray_getVertex(tileset_info->vtx,
        (ldata->i + ldata->j * ldata->mapx) * 4);

    idrot.id -= map->tilesets->data[ldata->tilesetindex].firstgid;
    ldata->tu = idrot.id % (ldata->txsize.x / ldata->tilesize);
    ldata->tv = idrot.id / (ldata->txsize.x / ldata->tilesize);
    quad[0].position = VEC2F(ldata->i * ldata->tilesize,
        ldata->j * ldata->tilesize);
    quad[1].position = VEC2F((ldata->i + 1) * ldata->tilesize,
        ldata->j * ldata->tilesize);
    quad[2].position = VEC2F((ldata->i + 1) * ldata->tilesize,
        (ldata->j + 1) * ldata->tilesize);
    quad[3].position = VEC2F(ldata->i * ldata->tilesize,
        (ldata->j + 1) * ldata->tilesize);
    idrot.id == -1 ? set_full_alpha(quad) : set_txrot_quad(quad, ldata, &idrot);
}

bool load_vertex_tileset(layer_tileset_info_t *tileset_info,
    usize_t tilesetchose, usize_t i, ig_map_t *map)
{
    struct vertex_loader ldata = {0, 0, 0, 0, map->width, map->height,
        sfTexture_getSize(tileset_info->texture),
        map->tilesets->data[tilesetchose].tilewidth, tilesetchose, i};

    D_ASSERT(tileset_info->vtx, NULL,
        "Vertex array could not be initted", false);
    sfVertexArray_setPrimitiveType(tileset_info->vtx, sfQuads);
    sfVertexArray_resize(tileset_info->vtx, map->width * map->height * 4);
    for (ldata.i = 0; ldata.i < ldata.mapx; ++ldata.i) {
        for (ldata.j = 0; ldata.j < ldata.mapy; ++ldata.j) {
            load_vertex_quad(tileset_info, &ldata, map);
        }
    }
}