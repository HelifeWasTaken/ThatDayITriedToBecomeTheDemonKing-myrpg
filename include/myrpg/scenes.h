/*
** EPITECH PROJECT, 2021
** scenes
** File description:
** Source code
*/

#ifndef B43C2285_FD29_46B0_AD7D_F251E1C0B355
#define B43C2285_FD29_46B0_AD7D_F251E1C0B355

#include "myrpg/entities.h"
#include "myrpg/game.h"
#include "myrpg/state.h"

enum scene_id {
    PLAY_SCENE,
    MENU_SCENE,
    KEY_CONFIG,
    SETTING_SCENE,
};

typedef struct play_state {} play_state_t;

int play_lifecycle(game_t *game);
int menu_lifecycle(game_t *game);
int key_lifecycle(game_t *game);
int setting_lifecycle(game_t *game);
bool function_button_settings(game_t *game, int i,
    parameters_t *parm, entity_t *entity);
bool load_button(game_t *game, settings_t *setting_button);

#endif /* B43C2285_FD29_46B0_AD7D_F251E1C0B355 */
