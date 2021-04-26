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

bool create_inventory(game_t *game UNUSED, entity_t *entity)
{
    inventory_t *inventory = ecalloc(sizeof(inventory_t), 1);

    D_ASSERT(inventory, NULL, "error malloc inventory", false);
    inventory->entity = entity;
    inventory->view = get_entity(game, VIEW)->instance;
    inventory->entity->pos = VEC2F(WINDOW_W / 2, WINDOW_H / 6);
    D_ASSERT(inventory->entity, NULL, "error:", false);
    inventory->clock = create_pausable_clock(game);
    D_ASSERT(inventory->clock, NULL, "error clock", false);
    inventory->box = sfCircleShape_create();
    D_ASSERT(inventory->box, NULL, "error box", false);
    sfCircleShape_setRadius(inventory->box, 60.0f);
    sfCircleShape_setPosition(inventory->box,
        VEC2F(WINDOW_W / 2 + 470, WINDOW_H / 6 + 20));
    inventory->is_visible = false;
    inventory->clock->has_game_pause = sfFalse;
    inventory->entity->z = 10000;
    entity->instance = inventory;
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

    sfSprite_setPosition(inventory->sprite, entity->pos);
    tick_pausable_clock(inventory->clock);
}

void draw_inventory(game_t *game UNUSED, entity_t *entity)
{
    inventory_t *inventory = entity->instance;

    if (inventory->is_visible == true) {
        set_view_type(game, inventory->view, HUD_VIEW);
        game->is_paused = true;
        sfRenderWindow_drawSprite(game->window, inventory->sprite, NULL);
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

    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        sfSprite_setTexture(inventory->sprite, inventory->over, sfFalse);
    } else {
        sfSprite_setTexture(inventory->sprite, inventory->texture, sfFalse);
    }

    if (sfMouse_isButtonPressed(sfMouseLeft)
        && sfFloatRect_contains(&rect, pos.x, pos.y)) {
        inventory->is_visible = false;
        return (true);
    }
    return (false);
}