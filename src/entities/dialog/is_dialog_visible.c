/*
** EPITECH PROJECT, 2021
** is_dialog_triggable
** File description:
** Source code
*/

#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include "myrpg/state.h"
#include "myrpg/util.h"
#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "distract/util.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include "distract/math.h"
#include "myrpg/cinema.h"

static bool count_levels_done(game_save_t *save)
{
    int count = 0;

    for (int i = 0; i < 4; i++) {
        if (save->levels_done[i])
            count++;
    }
    return (count);
}

bool is_dialog_visible(game_t *game, dialog_t *dialog)
{
    game_save_t *save = &get_game_state(game)->save;
    bool is_near_visible = (dialog->npc_type == 0);

    if (dialog->npc_type == 0 && dialog->boss_id != -1
        && save->levels_done[dialog->boss_id])
        return (false);
    if (dialog->npc_type != 0) {
        is_near_visible = (count_levels_done(save) == dialog->npc_type
            || count_levels_done(save) != -dialog->npc_type);
    }
    if (is_near_visible)
        return (v2fdistance(&dialog->hero->entity->pos,
            &dialog->entity->pos) < 30);
    return (false);
}