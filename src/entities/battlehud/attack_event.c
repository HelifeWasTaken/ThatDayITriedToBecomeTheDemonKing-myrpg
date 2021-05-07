/*
** EPITECH PROJECT, 2021
** attack_event
** File description:
** Source code
*/

#include "distract/entity.h"
#include "distract/game.h"
#include "myrpg/entities.h"
#include <SFML/Window/Event.h>

static bool handle_attack_button_click_events(game_t *game,
    battlehud_atk_button_t *button, sfEvent *event)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->btn);
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
                && event->type == sfEvtMouseButtonReleased) {
                    button->on_click(game, button);
                    return (true);
            }
    }
    return (false);
}

bool handle_attack_button_events(game_t *game,
    battlehud_atk_button_t *button, sfEvent *event)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->btn);
    sfMouseMoveEvent move;

    if (handle_attack_button_click_events(game, button, event))
        return (true);
    if (event->type == sfEvtMouseMoved) {
        move = event->mouseMove;
        button->is_mouse_over = sfFloatRect_contains(&bounds, move.x, move.y);
    }
    return (false);
}

bool handle_attack_buttons_events(game_t *game,
    battlehud_t *battlehud, sfEvent *event)
{
    for (int i = 0; i < 3; i++) {
        if (handle_attack_button_events(game, &battlehud->atk_btn[i],
            event))
            return (true);
    }
    return (false);
}