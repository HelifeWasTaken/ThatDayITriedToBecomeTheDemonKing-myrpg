/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** load_equipment
*/

#include "distract/game.h"
#include "distract/util.h"
#include "distract/window.h"
#include "distract/scene.h"
#include "myrpg/asset.h"
#include "distract/entity.h"
#include "distract/debug.h"
#include "myrpg/entities.h"
#include "myrpg/scenes.h"
#include "myrpg/state.h"
#include "stdlib.h"
#include "myrpg/scenes.h"
#include "myrpg/util.h"
#include "distract/util.h"

void start_equimpent(game_t *game)
{
    game_state_t *state = game->state;

    for (int index = 0; index  != 5; index++) {
        state->save.equipment[index].id = 0;
        state->save.equipment[index].nb = 0;
        state->save.equipment[index].type = EMPTY;
    }
}