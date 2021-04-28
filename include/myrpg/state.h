/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** parameters
*/

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include "distract/entity.h"
#include "myrpg/game.h"
#include "define.h"
#include <stdint.h>
#include "iron_goat/deser.h"

    enum item_type {
        EMPTY,
        CHESTPLATE,
        HELMET,
        RING,
        SHIELD,
        WEAPON,
        ITEM
    };

    typedef struct parameters {
        float music_vol;
        float vfx_vol;
        float voice_vol;
        bool music_muted;
        bool vfx_muted;
        bool voice_muted;
    } parameters_t;

    typedef struct item {
        int nb;
        int type;
        int id;
    } item_t;

    typedef struct game_save {
        ///
        /// Map to load when loading save
        ///
        int map_id;

        ///
        /// inventory
        ///
        item_t item[15];
        ///
        /// Position where to spawn player in map
        ///
        sfVector2f player_pos;

        ///
        /// Mana
        ///
        int player_mana;

        ///
        /// Health points
        ///
        int player_hp;

        ///
        /// Level
        ///
        int player_lv;
    } game_save_t;

    typedef struct game_state {
        parameters_t params;
        game_save_t save;
        ig_map_t map;
        usize_t z;
    } game_state_t;

#endif /* !PARAMETERS_H_ */
