/*
** EPITECH PROJECT, 2021
** tileset
** File description:
** tile
*/

#ifndef __IRON_GOAT__TILESET__H__
    #define __IRON_GOAT__TILESET__H__

    #include <iron_goat/deser.h>

    bool load_iron_goat_tileset_grid(struct json *conf,
        struct iron_goat_tileset *self);
    bool load_iron_goat_tileset_tileoffset(struct json *conf,
        struct iron_goat_tileset *self);
    bool load_iron_goat_tileset_transparent_color(struct json *conf,
        struct iron_goat_tileset *self);
    bool load_iron_goat_tileset_properties(struct json *conf,
        struct iron_goat_tileset *self);

#endif
