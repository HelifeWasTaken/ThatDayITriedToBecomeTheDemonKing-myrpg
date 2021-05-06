/*
** EPITECH PROJECT, 2021
** battle
** File description:
** Source code
*/

#ifndef A61D752A_1EA4_4883_A475_8379C585E529
#define A61D752A_1EA4_4883_A475_8379C585E529
#include "distract/animable.h"
#include "distract/game.h"
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#undef ABS
#include <iron_goat/deser.h>

typedef enum battle_animation_type {
    BAT_ANIM_IDLE    = 0,
    BAT_ANIM_ATTACK  = 1,
    BAT_ANIM_DEATH   = 2,
    BAT_ANIM_ITEM    = 3,
    BAT_ANIM_SPELL_1 = 8,
    BAT_ANIM_SPELL_2 = 9,
    BAT_ANIM_SPELL_3 = 10
} battle_animation_type_t;

typedef enum battle_spell_type {
    BST_NOT_A_SPELL,
    BST_AIR
} battle_spell_type_t;

typedef struct battle_spell {
    char *name;
    int mana;
    int efficiency;
    battle_spell_type_t type;
    battle_animation_type_t anim;
    char *attack_fx_file;
    int attack_fx_frames_per_line;
    int attack_fx_frames_count;
    sfVector2f attack_fx_size;
    sfTexture *attack_fx_texture;
} battle_spell_t;

typedef struct battle_opponent {
    sfVector2f scale;
    animable_t animable;
    animable_info_t animable_info;
    sfVector2f pos;
    sfVector2f pos_offset;
    char *name;
    char *asset_file;
    sfIntRect asset_rect;
    int level;
    int health;
    int max_mana;
    int mana;
    battle_spell_t spells[20];
} battle_opponent_t;

struct battle_background_pair {
    char *world_id;
    char *file;
    sfIntRect rect;
    sfVector2f size;
};

typedef struct boss_data {
    char *name;
    char *file_path;
    int frame;
    sfVector2f rect_size;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f pos;
    int hp;
    int mana;
    sfVector2f scale;
    sfVector2f pos_offset;
    animable_info_t animable_info;
    int boss_id;
} boss_data_t;

int start_battle(game_t *game, int boss_id);

void destroy_boss_data(boss_data_t *my_pnj);

INIT_VECTOR(boss_vector, struct boss_data, destroy_boss_data);

bool load_boss_data_loop(struct json *pnj_conf,
    VECTOR(boss_vector) **pnj_vector_tab);

#endif /* A61D752A_1EA4_4883_A475_8379C585E529 */
