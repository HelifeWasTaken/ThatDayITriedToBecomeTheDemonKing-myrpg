/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_equipment_slot
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
#include "myrpg/state.h"

bool create_texture_item(game_t *game)
{
    for (int index = 0; index != MAX_ITEM; index++) {
        game->texture[index] = create_texture(game,
            game->item_loaded[index].path, NULL);
        D_ASSERT(game->texture[index], NULL, "error", false);
    }
    return (true);
}

void place_equipment_slot(game_t *game UNUSED, inventory_t *inv)
{
    int width = WINDOW_W / 2.5 + 50;
    int height = WINDOW_H / 2 + 380;

    for (int index = 0; index != 5; index++) {
        sfSprite_setPosition(inv->equipment[index].sprite,
            VEC2F(width + (85 * index), height));
    }
}

bool init_equiment_slot(game_t *game, inventory_t *inventory)
{
    for (int index = 0; index != 5; index++) {
        inventory->equipment[index].sprite = create_sprite(game->texture[0], NULL);
        D_ASSERT(inventory->equipment[index].sprite, NULL,
            "error sprite item", false);
        sfSprite_setScale(inventory->equipment[index].sprite, VEC2F(5, 5));
        inventory->equipment[index].id = 0;
    }
    place_equipment_slot(game, inventory);
    inventory->equipment[0].id = WEAPON;
    inventory->equipment[1].id = SHIELD;
    inventory->equipment[2].id = CHESTPLATE;
    inventory->equipment[3].id = HELMET;
    inventory->equipment[4].id = RING;
    return (true);
}