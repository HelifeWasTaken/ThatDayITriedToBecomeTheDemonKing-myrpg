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

static const inventory_item_t item_id[4] = {
    {"asset/item/empty.png", EMPTY},
    {"asset/item/banane.png", ITEM},
    {"asset/item/sword.png", WEAPON},
    {"asset/item/woodshield.png", SHIELD}
};

bool place(game_t *game, entity_t *entity, int i)
{
    inventory_t *inv = entity->instance;
    game_state_t *state = game->state;
    sfTexture *texture = NULL;

    if (state->save.item[i].type == EMPTY
        && inv->is_deplacement == true) {
            inv->is_deplacement = false;
            state->save.item[i].id = inv->item_id;
            state->save.item[i].type = item_id[inv->item_id].type;
            inv->mouse_state = 0;
            texture = create_texture(game, item_id[0].path, NULL);
            D_ASSERT(texture, NULL, "error texture", false);
            sfSprite_setTexture(inv->cursor_item, texture, sfFalse);
            return (true);
    }
    return (false);
}

bool deplacement(game_t *game, entity_t *entity, int i)
{
    inventory_t *inventory = entity->instance;
    game_state_t *state = game->state;
    sfTexture *texture = NULL;

    if (state->save.item[i].type != EMPTY
        && inventory->is_deplacement == false) {
            texture = create_texture(game,
                item_id[state->save.item[i].id].path, NULL);
            D_ASSERT(texture, NULL, "error texture", false)
            sfSprite_setTexture(inventory->cursor_item, texture, sfFalse);
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
        rect = sfSprite_getGlobalBounds(inventory->inventory[index]);
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
    sfTexture *texture = NULL;

    if (inventory->is_deplacement == true) {
        texture = create_texture(game, item_id[0].path, NULL);
        D_ASSERT(texture, NULL, "error quit texture", false);
        sfSprite_setTexture(inventory->cursor_item, texture, sfFalse);
        state->save.item[inventory->mouse_state].id = inventory->item_id;
        state->save.item[inventory->mouse_state].type
            = item_id[inventory->item_id].type;
        inventory->is_deplacement = false;
        return (true);
    }
    return (false);
}