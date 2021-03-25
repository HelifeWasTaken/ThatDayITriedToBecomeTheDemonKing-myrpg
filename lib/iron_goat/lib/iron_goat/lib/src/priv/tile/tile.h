/*
** EPITECH PROJECT, 2021
** iron_goat
** File description:
** tile.h
*/

#ifndef _TILE_H_
    #define _TILE_H_

    #include <iron_goat/deser.h>

    bool load_iron_goat_tile_animation(struct json *conf,
            struct iron_goat_tile *self);
    bool load_iron_goat_tile_objectgroup(struct json *conf,
            struct iron_goat_tile *self);
    bool load_iron_goat_tile_properties(struct json *conf,
            struct iron_goat_tile *self);
    bool load_iron_goat_tile_terrain(struct json *conf,
            struct iron_goat_tile *self);
    bool load_iron_goat_tile_probabilities(struct json *conf,
            struct iron_goat_tile *self);

#endif /* _TILE_H_ */
