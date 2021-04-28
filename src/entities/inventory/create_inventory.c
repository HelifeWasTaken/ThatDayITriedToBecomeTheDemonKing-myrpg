/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_inventory
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

static const inventory_item_t item_id[4] = {
    {"asset/item/empty.png", EMPTY},
    {"asset/item/banane.png", ITEM},
    {"asset/item/sword.png", WEAPON},
    {"asset/item/woodshield.png", SHIELD}
};

bool init_cursor(game_t *game, entity_t *entity)
{
    inventory_t *inventory = entity->instance;
    sfTexture *texture = create_texture(game, item_id[0].path, NULL);

    D_ASSERT(texture, NULL, "error sprite mouse", false);
    inventory->cursor_item = create_sprite(texture, NULL);
    D_ASSERT(inventory->cursor_item, NULL, "sprite", false);
    sfSprite_setScale(inventory->cursor_item, VEC2F(3, 3));
    inventory->mouse_state = 0;
    inventory->is_deplacement = false;
    return (true);
}

sfSprite *init_inventory(UNUSED game_t *game, UNUSED entity_t *entity)
{
    inventory_t *inventory = entity->instance;
    sfSprite *sprite = NULL;

    inventory->texture = create_texture(game, INV_TEX, NULL);
    D_ASSERT(init_cursor(game, entity), false, "error", false);
    inventory->over = create_texture(game, INV_TEX_OVER, NULL);
    D_ASSERT(inventory->texture, NULL, "error texture inventory", NULL);
    D_ASSERT(inventory->over, NULL, "error texture over inventory", NULL);
    sprite = create_sprite(inventory->texture, NULL);
    D_ASSERT(sprite, NULL, "error texture", NULL);
    sfSprite_setScale(sprite, VEC2F(2.5, 2.5));
    return (sprite);
}

void place_item(UNUSED game_t *game, entity_t *entity)
{
    inventory_t * inventory = entity->instance;
    int z = 0;
    int width = WINDOW_W / 2.5 + 50;
    int height = WINDOW_H / 2 - 150;

    do {
        if (z == 5 && z != 0) {
            width -= (85 * z);
            height += 85;
        }
        if (z == 10) {
            width -= (85 * 5);
            height += 85;
        }
        sfSprite_setPosition(inventory->inventory[z],
            VEC2F(width + (85 * z), height));
        z++;
    } while (z != 15);
}

bool init_inventory_item(game_t *game, entity_t *entity)
{
    inventory_t *inventory = entity->instance;
    sfTexture *texture = NULL;

    inventory->inventory = ecalloc(sizeof(sfSprite *), 15);
    D_ASSERT(inventory->inventory, NULL, "error sprite inventory", false);
    for (int i = 0; i != 15; i++) {
        texture = create_texture(game, item_id[0].path, NULL);
        D_ASSERT(texture, NULL, "error text inventory item", false);
        inventory->inventory[i] = create_sprite(texture, NULL);
        D_ASSERT(inventory->inventory[i], NULL, "error sprite item", false);
        sfSprite_setScale(inventory->inventory[i], VEC2F(5, 5));
    }
    place_item(game, entity);
    return (true);
}

bool update_item(game_t *game, entity_t *entity)
{
    inventory_t *inventory = entity->instance;
    game_state_t *state = game->state;
    sfTexture *texture = NULL;

    for (int i = 0; i != 15; i++) {
        texture = create_texture(game,
            item_id[state->save.item[i].id].path, NULL);
        D_ASSERT(texture, NULL, "error update texture", false);
        sfSprite_setTexture(inventory->inventory[i], texture, sfFalse);
        sfSprite_setScale(inventory->inventory[i], VEC2F(5, 5));
        D_ASSERT(inventory->inventory[i], NULL,
            "error update inventory", false);
    }
    return (true);
}
