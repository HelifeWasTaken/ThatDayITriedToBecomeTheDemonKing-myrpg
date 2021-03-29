/*
** EPITECH PROJECT, 2021
** load
** File description:
** text
*/

#include "myrpg/map.h"

static void set_texture_coords_rot_zero(
    struct vertex_loader_rotation_data *data)
{
    data->quad[0].texCoords = VEC2F(
        data->tu * data->size->tilex,
        data->tv * data->size->tiley);
    data->quad[1].texCoords = VEC2F(
        (data->tu + 1) * data->size->tilex,
        data->tv * data->size->tiley);
    data->quad[2].texCoords = VEC2F(
        (data->tu + 1) * data->size->tilex,
        (data->tv + 1) * data->size->tiley);
    data->quad[3].texCoords = VEC2F(
        data->tu * data->size->tilex,
        (data->tv + 1) * data->size->tiley);
}

static void set_texture_coords_rot_ninety(
    struct vertex_loader_rotation_data *data)
{
    data->quad[1].texCoords = VEC2F(
        data->tu * data->size->tilex,
        data->tv * data->size->tiley);
    data->quad[2].texCoords = VEC2F(
        (data->tu + 1) * data->size->tilex,
        data->tv * data->size->tiley);
    data->quad[3].texCoords = VEC2F(
        (data->tu + 1) * data->size->tilex,
        (data->tv + 1) * data->size->tiley);
    data->quad[0].texCoords = VEC2F(
        data->tu * data->size->tilex,
        (data->tv + 1) * data->size->tiley);
}

static void set_texture_coords_rot_oneeighty(
    struct vertex_loader_rotation_data *data)
{
    data->quad[2].texCoords = VEC2F(
        data->tu * data->size->tilex,
        data->tv * data->size->tiley);
    data->quad[3].texCoords = VEC2F(
        (data->tu + 1) * data->size->tilex,
        data->tv * data->size->tiley);
    data->quad[0].texCoords = VEC2F(
        (data->tu + 1) * data->size->tilex,
        (data->tv + 1) * data->size->tiley);
    data->quad[1].texCoords = VEC2F(
        data->tu * data->size->tilex,
        (data->tv + 1) * data->size->tiley);
}

static void set_texture_coords_rot_twoseventy(
    struct vertex_loader_rotation_data *data)
{
    data->quad[3].texCoords = VEC2F(
        data->tu * data->size->tilex,
        data->tv * data->size->tiley);
    data->quad[0].texCoords = VEC2F(
        (data->tu + 1) * data->size->tilex,
        data->tv * data->size->tiley);
    data->quad[1].texCoords = VEC2F(
        (data->tu + 1) * data->size->tilex,
        (data->tv + 1) * data->size->tiley);
    data->quad[2].texCoords = VEC2F(
        data->tu * data->size->tilex,
        (data->tv + 1) * data->size->tiley);
}

static const struct vertex_funcpointer_rotation_set ROT_SET[] = {
    {set_texture_coords_rot_zero},
    {set_texture_coords_rot_ninety},
    {set_texture_coords_rot_oneeighty},
    {set_texture_coords_rot_twoseventy}
};

void set_texture_coords(struct vertex_loader_rotation_data *data)
{
    ROT_SET[data->rotation].fun(data);
}