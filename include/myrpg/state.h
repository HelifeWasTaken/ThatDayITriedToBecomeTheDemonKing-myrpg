/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** parameters
*/

#ifndef STATE_H_
    #define STATE_H_

    #include "distract/entity.h"
    #include "myrpg/game.h"
    #include "define.h"
    #include <stdint.h>
    #include "iron_goat/deser.h"
    #include <SFML/Audio.h>

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

    typedef struct inventory_save {
        int nb;
        int type;
        int id;
    } inventory_save_t;

    enum cinematics_id {
        VILLAGE_CINEMATIC,
        MAP_MONDE_CINEMATIC,
        DESERT_VILLAGE_CINEMATIC,
        DESERT_BATTLE_CINEMATIC,
        VOLCANO_CINEMATIC,
        FOREST_CINEMATIC,
        CASTLE_CINEMATIC,
        INSIDE_CASTLE_CINEMATIC,
        LAST_CINEMATIC,
        CINEMATIC_COUNT
    };

    #define IS_GAME_FINISHED(game) \
        (get_game_state(game)->save.levels_done[0] && \
        get_game_state(game)->save.levels_done[1] && \
        get_game_state(game)->save.levels_done[2] && \
        get_game_state(game)->save.levels_done[3])

    typedef struct game_save {
        char map_id[256];
        inventory_save_t item[15];
        inventory_save_t equipment[5];
        sfVector2f player_pos;
        int player_xp;
        int player_hp;
        int player_lv;
        uint16_t cinematics;
        uint32_t cinematics_end_count;
        bool levels_done[4];
    } game_save_t;

    typedef struct game_state {
        parameters_t params;
        game_save_t save;
        ig_map_t map;
        int last_boss_id;
        usize_t z;
        sfMusic *end_music;
    } game_state_t;

#endif /* !PARAMETERS_H_ */