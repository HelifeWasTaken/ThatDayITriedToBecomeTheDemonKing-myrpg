/*
** EPITECH PROJECT, 2021
** wang
** File description:
** set
*/

#ifndef __IRON_GOAT__WANGSET__H__
    #define __IRON_GOAT__WANGSET__H__

    #include <iron_goat/deser.h>

    bool load_iron_goat_wangset_cornercolors(struct json *conf,
        struct iron_goat_wangset *self);
    bool load_iron_goat_wangset_edgecolors(struct json *conf,
        struct iron_goat_wangset *self);

#endif
