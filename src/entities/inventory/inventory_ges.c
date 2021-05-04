/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory_ges
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
#include <stdio.h>

bool place(game_t *game, entity_t *entity, int i)
{
    inventory_t *inv = entity->instance;
    game_state_t *state = game->state;

    if (state->save.item[i].type == EMPTY
        && inv->is_deplacement == true) {
            inv->is_deplacement = false;
            state->save.item[i].id = inv->item_id;
            state->save.item[i].type = inv->inventory[inv->item_id].type;
            inv->mouse_state = 0;
            sfSprite_setTexture(inv->cursor_item, game->texture[0], sfFalse);
            inv->item_id = 0;
            return (true);
    }
    return (false);
}

bool deplacement(game_t *game, entity_t *entity, int i)
{
    inventory_t *inventory = entity->instance;
    game_state_t *state = game->state;

    if (state->save.item[i].type != EMPTY
        && inventory->is_deplacement == false) {
            inventory->is_deplacement = true;
            inventory->item_id = state->save.item[i].id;
            state->save.item[i].id = 0;
            state->save.item[i].type = EMPTY;
            inventory->mouse_state = i;
            return (true);
    }
    return (place(game, entity, i));
}

void inventory_management(game_t *game, entity_t *entity)
{
    inventory_t *inventory = entity->instance;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect rect;

    for (int index = 0; index != 15; index++) {
        rect = sfSprite_getGlobalBounds(inventory->inventory[index].sprite);
        if (sfMouse_isButtonPressed(sfMouseLeft)
            && sfFloatRect_contains(&rect, pos.x, pos.y)
            && inventory->clock->time >= 0.5) {
                inventory->clock->time = 0;
                deplacement(game, entity, index);
        }
    }
}

bool update_cursor(game_t *game, entity_t *entity)
{
    inventory_t *inventory = entity->instance;
    game_state_t *state = game->state;

    if (inventory->is_deplacement == true) {
        state->save.item[inventory->mouse_state].id = inventory->item_id;
        state->save.item[inventory->mouse_state].type
            = game->item_loaded[inventory->item_id].type;
        inventory->is_deplacement = false;
        return (true);
    }
    return (false);
}