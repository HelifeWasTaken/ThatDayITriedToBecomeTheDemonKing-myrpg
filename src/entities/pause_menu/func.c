/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** func
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

void function_button_pause(game_t *game, entity_t *entity, int i)
{
    pause_menu_t *pause = entity->instance;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        switch (i) {
        case CONTINUE_MENU_BTN:
            pause->is_display = false;
            break;
        case MENU_BTN:
            switch_to_scene(game, MENU_SCENE);
            break;
        case QUIT_BTN:
            switch_to_scene(game, -1);
            break;
        }
    }
}