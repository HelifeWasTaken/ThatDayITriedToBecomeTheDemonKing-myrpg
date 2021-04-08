/*
** EPITECH PROJECT, 2021
** settxrot
** File description:
** qua
*/

#include "myrpg/map/map.h"

static void set_texture_coords_rot_zero(sfVertex *quad,
    struct vertex_loader *data)
{
    quad[0].texCoords = VEC2F(
        data->tu * data->tilesize, data->tv * data->tilesize);
    quad[1].texCoords = VEC2F(
        (data->tu + 1) * data->tilesize, data->tv * data->tilesize);
    quad[2].texCoords = VEC2F(
        (data->tu + 1) * data->tilesize, (data->tv + 1) * data->tilesize);
    quad[3].texCoords = VEC2F(
        data->tu * data->tilesize, (data->tv + 1) * data->tilesize);
}

static void set_texture_coords_rot_ninety(sfVertex *quad,
    struct vertex_loader *data)
{
    quad[1].texCoords = VEC2F(
        data->tu * data->tilesize, data->tv * data->tilesize);
    quad[2].texCoords = VEC2F(
        (data->tu + 1) * data->tilesize, data->tv * data->tilesize);
    quad[3].texCoords = VEC2F(
        (data->tu + 1) * data->tilesize, (data->tv + 1) * data->tilesize);
    quad[0].texCoords = VEC2F(
        data->tu * data->tilesize, (data->tv + 1) * data->tilesize);
}

static void set_texture_coords_rot_oneeighty(sfVertex *quad,
    struct vertex_loader *data)
{
    quad[2].texCoords = VEC2F(
        data->tu * data->tilesize, data->tv * data->tilesize);
    quad[3].texCoords = VEC2F(
        (data->tu + 1) * data->tilesize, data->tv * data->tilesize);
    quad[0].texCoords = VEC2F(
        (data->tu + 1) * data->tilesize, (data->tv + 1) * data->tilesize);
    quad[1].texCoords = VEC2F(
        data->tu * data->tilesize, (data->tv + 1) * data->tilesize);
}

static void set_texture_coords_rot_twoseventy(sfVertex *quad,
    struct vertex_loader *data)
{
    quad[3].texCoords = VEC2F(
        data->tu * data->tilesize, data->tv * data->tilesize);
    quad[0].texCoords = VEC2F(
        (data->tu + 1) * data->tilesize, data->tv * data->tilesize);
    quad[1].texCoords = VEC2F(
        (data->tu + 1) * data->tilesize, (data->tv + 1) * data->tilesize);
    quad[2].texCoords = VEC2F(
        data->tu * data->tilesize, (data->tv + 1) * data->tilesize);
}

static const (*ROT_FUN[])(sfVertex *, struct vertex_loader *) = {
    set_texture_coords_rot_zero,
    set_texture_coords_rot_ninety,
    set_texture_coords_rot_oneeighty,
    set_texture_coords_rot_twoseventy
};

void set_txrot_quad(sfVertex *quad, struct vertex_loader *ldata,
    struct tile_id_rot *idrot)
{
    ROT_FUN[idrot->rot](quad, ldata);
}