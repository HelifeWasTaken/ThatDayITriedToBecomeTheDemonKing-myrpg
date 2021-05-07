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

struct button_checker_battle {
    sfMouseButtonEvent click;
    game_t *game;
    sfEvent *event;
    sfFloatRect bounds;
    battlehud_atk_button_t *button;
    sfVector2f pos;
};

bool handle_attack_button_click_events_part2(
        struct button_checker_battle *checker)
{
    if (checker->event->type == sfEvtMouseButtonReleased)
        checker->button->clicked = false;
    if (checker->event->type == sfEvtMouseButtonPressed
            || checker->event->type == sfEvtMouseButtonReleased) {
        checker->click = checker->event->mouseButton;
        if (checker->click.button == sfMouseLeft
                && sfFloatRect_contains(&checker->bounds,
                    checker->pos.x, checker->pos.y))
            checker->button->clicked =
                (checker->event->type == sfEvtMouseButtonPressed);
        if (checker->click.button == sfMouseLeft
                && sfFloatRect_contains(&checker->bounds,
                    checker->pos.x, checker->pos.y)
                && checker->event->type == sfEvtMouseButtonReleased) {
            checker->button->on_click(checker->game, checker->button);
            return (true);
        }
    }
    return (false);
}

bool handle_attack_button_click_events(game_t *game,
        battlehud_atk_button_t *button, sfEvent *event)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(button->btn);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfMouseButtonEvent click = {0};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window,
            mouse, game->gui_view);

    return (handle_attack_button_click_events_part2(
        &(struct button_checker_battle){
            click, game, event, bounds, button, pos
        }));
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
