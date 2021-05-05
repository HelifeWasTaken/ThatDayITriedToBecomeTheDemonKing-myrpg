/*
** EPITECH PROJECT, 2020
** button
** File description:
** Source code
*/

#include <distract/game.h>
#include <distract/entity.h>
#include <distract/resources.h>
#include <distract/graphics.h>
#include <myrpg/entities.h>
#include <stdlib.h>

bool handle_button_click_events(game_t *game, entity_t *entity, sfEvent *event)
{
    gui_button_t *button = entity->instance;
    sfFloatRect bounds = sfText_getGlobalBounds(button->text);
    sfMouseButtonEvent click;

    if (event->type == sfEvtMouseButtonReleased)
        button->clicked = false;
    if (event->type == sfEvtMouseButtonPressed
        || event->type == sfEvtMouseButtonReleased) {
            click = event->mouseButton;
            if (click.button == sfMouseLeft
                && sfFloatRect_contains(&bounds, click.x, click.y))
                    button->clicked = (event->type == sfEvtMouseButtonPressed);
            if (click.button == sfMouseLeft
                && sfFloatRect_contains(&bounds, click.x, click.y)
                && event->type == sfEvtMouseButtonReleased
                && button->is_enabled) {
                    button->on_click(game, entity);
                    return (true);
            }
    }
    return (false);
}