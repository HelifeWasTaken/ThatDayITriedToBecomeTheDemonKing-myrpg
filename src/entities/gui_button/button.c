/*
** EPITECH PROJECT, 2020
** button
** File description:
** Source code
*/

#include <SFML/Graphics/Text.h>
#include <distract/game.h>
#include <distract/entity.h>
#include <distract/resources.h>
#include <distract/graphics.h>
#include "distract/debug.h"
#include "erty/eprintf.h"
#include "myrpg/asset.h"
#include "myrpg/entities.h"
#include "distract/util.h"
#include <stdlib.h>

bool handle_button_click_events(game_t *game, entity_t *entity, sfEvent *event);

bool create_button(game_t *game, entity_t *entity)
{
    sfFont *font = create_font(game, "asset/04b_19.ttf");
    gui_button_t *button = dcalloc(1, sizeof(gui_button_t));

    D_ASSERT(button, NULL, "button could not be init", false);
    D_ASSERT(font, NULL, "button font could not be init", false);
    entity->z = 10000;
    button->entity = entity;
    button->mouse_entered = false;
    button->clicked = false;
    button->text = sfText_create();
    button->title = "";
    button->is_centered = false;
    button->is_enabled = true;
    button->on_click = not_implemented;
    D_ASSERT(button->text, NULL, "button text could not be init", false);
    sfText_setFont(button->text, font);
    entity->instance = button;
    entity->draw_on_gui = true;
    return (true);
}

void update_button(game_t *game UNUSED, entity_t *entity)
{
    gui_button_t *button = entity->instance;
    sfFloatRect new_bounds = sfText_getGlobalBounds(button->text);
    sfVector2f position = entity->pos;

    sfText_setString(button->text, button->title);
    if (button->mouse_entered) {
        sfText_setColor(button->text, sfYellow);
        sfText_setScale(button->text, (sfVector2f) { 1.3f, 1.3f });
        new_bounds = sfText_getGlobalBounds(button->text);
        position = VEC2F(entity->pos.x - new_bounds.width / 6,
            entity->pos.y - new_bounds.height / 6);
    } else {
        sfText_setColor(button->text, sfWhite);
        sfText_setScale(button->text, (sfVector2f) { 1, 1 });
    }
    if (button->clicked)
        sfText_setColor(button->text, sfGreen);
    sfText_setPosition(button->text, position);
    if (button->is_centered)
        center_text_x(button->text, 0, game->mode.width);
}

bool handle_button_events(game_t *game, entity_t *entity, sfEvent *event)
{
    gui_button_t *button = entity->instance;
    sfFloatRect bounds = sfText_getGlobalBounds(button->text);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f move = sfRenderWindow_mapPixelToCoords(game->window,
            mouse, game->gui_view);

    if (handle_button_click_events(game, entity, event))
        return (button->is_enabled);
    if (event->type == sfEvtMouseMoved) {
        button->mouse_entered = sfFloatRect_contains(&bounds, move.x, move.y);
    }
    return (false);
}

void draw_button(game_t *game, entity_t *entity)
{
    gui_button_t *button = entity->instance;

    if (!button->is_enabled)
        return;
    sfRenderWindow_drawText(game->window, button->text, NULL);
}

void destroy_button(game_t *game UNUSED, entity_t *entity)
{
    gui_button_t *button = entity->instance;

    sfText_destroy(button->text);
    free(button);
}
