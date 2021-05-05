/*
** EPITECH PROJECT, 2021
** tileid_androt
** File description:
** myrpg
*/

#include "myrpg/map/map.h"

static const uint64_t FLIP_H_FLAG = 0x80000000;
static const uint64_t FLIP_V_FLAG = 0x40000000;
static const uint64_t FLIP_D_FLAG = 0x20000000;

struct tile_id_rot get_real_tile_id_and_rotation(u64_t id)
{
    uint64_t pure_id = id & ~(FLIP_H_FLAG | FLIP_V_FLAG | FLIP_D_FLAG);

    if (id < FLIP_D_FLAG)
        return ((struct tile_id_rot){ROT_0, pure_id});
    if ((id & FLIP_H_FLAG) && (id & FLIP_D_FLAG))
        return ((struct tile_id_rot){ROT_90, pure_id});
    if ((id & FLIP_H_FLAG) && (id & FLIP_V_FLAG))
        return ((struct tile_id_rot){ROT_180, pure_id});
    return ((struct tile_id_rot){ROT_270, pure_id});
}