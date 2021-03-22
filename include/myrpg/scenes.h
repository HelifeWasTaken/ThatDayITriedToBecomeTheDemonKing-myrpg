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

enum scene_id {
    PLAY_SCENE,
    MENU_SCENE,
};

typedef struct play_state {} play_state_t;

int play_lifecycle(game_t *game);
int menu_lifecycle(game_t *game);

#endif /* B43C2285_FD29_46B0_AD7D_F251E1C0B355 */
