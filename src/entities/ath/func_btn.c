/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** func_btn
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/scenes.h"

bool func_btn_jar(UNUSED game_t *game, UNUSED entity_t *entity)
{
    return (false);
}

bool func_btn_setting(UNUSED game_t *game, UNUSED entity_t *entity)
{
    sfView *view = game->view;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        set_game_view(game, game->gui_view);
        await_scene(game, SETTING_SCENE);
        set_game_view(game, view);
        return (true);
    }
    return (false);
}

bool func_btn_save(UNUSED game_t *game, UNUSED entity_t *entity)
{
    pause_menu_t *pause = get_instance(game, PAUSE_MENU);
    inventory_t *inv = get_instance(game, INVENTORY);

    D_ASSERT(pause, NULL, "ERROR func btn inv", false);
    D_ASSERT(inv, NULL, "error instance btn inv", false);
    if (game->is_paused != true && inv->is_visible != true) {
        pause->is_display = true;
        game->is_paused = true;
        return (true);
    }
    return (false);
}

bool func_btn_quest(UNUSED game_t *game, UNUSED entity_t *entity)
{
    return (false);
}

bool func_btn_inventory(UNUSED game_t *game, UNUSED entity_t *entity)
{
    inventory_t *inventory = get_instance(game, INVENTORY);

    D_ASSERT(inventory, NULL, "ERROR func btn inv", false);
    if (game->is_paused != true) {
        inventory->is_visible = true;
        game->is_paused = true;
        return (true);
    }
    return (false);
}
