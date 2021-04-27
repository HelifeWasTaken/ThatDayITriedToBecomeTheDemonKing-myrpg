/*
** EPITECH PROJECT, 2020
** inventory
** File description:
** Entity
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

bool create_inventory(game_t *game UNUSED, entity_t *entity)
{
    inventory_t *inventory = ecalloc(sizeof(inventory_t), 1);

    D_ASSERT(inventory, NULL, "error malloc inventory", false);
    inventory->entity = entity;
    inventory->view = get_entity(game, VIEW)->instance;
    inventory->entity->pos = VEC2F(WINDOW_W / 2.5, WINDOW_H / 6);
    D_ASSERT(inventory->entity, NULL, "error:", false);
    inventory->clock = create_pausable_clock(game);
    D_ASSERT(inventory->clock, NULL, "error clock", false);
    inventory->box = sfCircleShape_create();
    D_ASSERT(inventory->box, NULL, "error box", false);
    sfCircleShape_setRadius(inventory->box, 60.0f);
    inventory->is_visible = false;
    inventory->clock->has_game_pause = sfFalse;
    inventory->entity->z = 10000;
    entity->instance = inventory;
    init_inventory_item(game, entity);
    inventory->sprite = init_inventory(game, entity);
    return (true);
}

void destroy_inventory(game_t *game UNUSED, entity_t *entity)
{
    inventory_t *inventory = entity->instance;

    sfSprite_destroy(inventory->sprite);
    destroy_pausable_clock(inventory->clock);
    free(inventory);
}

void update_inventory(game_t *game UNUSED, entity_t *entity)
{
    inventory_t *inventory = entity->instance;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    sfSprite_setPosition(inventory->cursor_item, VEC2F(pos.x, pos.y));
    if (update_item(game, entity) == false) {
        return;
    }
    sfSprite_setPosition(inventory->sprite, entity->pos);
    sfCircleShape_setPosition(inventory->box,
        VEC2F(WINDOW_W / 2.5 + 470, WINDOW_H / 6 + 20));
    tick_pausable_clock(inventory->clock);
}

void draw_inventory(game_t *game UNUSED, entity_t *entity)
{
    inventory_t *inventory = entity->instance;

    if (inventory->is_visible == true) {
        set_view_type(game, inventory->view, HUD_VIEW);
        game->is_paused = true;
        sfRenderWindow_drawSprite(game->window, inventory->sprite, NULL);
        for (int i = 0; i != 15; i++) {
            sfRenderWindow_drawSprite(game->window,
                inventory->inventory[i], NULL);
        }
        sfRenderWindow_drawSprite(game->window, inventory->cursor_item, NULL);
    } else {
        game->is_paused = false;
    }
}

bool handle_inventory_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    inventory_t *inventory = entity->instance;
    sfFloatRect rect = sfCircleShape_getGlobalBounds(inventory->box);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    inventory_management(game, entity);
    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        sfSprite_setTexture(inventory->sprite, inventory->over, sfFalse);
    } else {
        sfSprite_setTexture(inventory->sprite, inventory->texture, sfFalse);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && sfFloatRect_contains(&rect, pos.x, pos.y)) {
        update_cursor(game, entity);
        inventory->is_visible = false;
        return (true);
    }
    return (false);
}