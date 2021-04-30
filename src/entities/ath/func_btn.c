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

bool func_btn_jar(UNUSED game_t *game, UNUSED entity_t *entity)
{
    return (false);
}

bool func_btn_setting(UNUSED game_t *game, UNUSED entity_t *entity)
{
    return (false);
}

bool func_btn_save(UNUSED game_t *game, UNUSED entity_t *entity)
{
    return (false);
}

bool func_btn_quest(UNUSED game_t *game, UNUSED entity_t *entity)
{
    return (false);
}

bool func_btn_inventory(UNUSED game_t *game, UNUSED entity_t *entity)
{
    inventory_t *inventory = get_entity(game, INVENTORY)->instance;

    D_ASSERT(inventory, NULL, "ERROR func btn inv", false);
    if (game->is_paused != true) {
        inventory->is_visible = true;
        return (true);
    }
    return (false);
}