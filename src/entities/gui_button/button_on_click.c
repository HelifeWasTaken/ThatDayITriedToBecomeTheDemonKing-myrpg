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

struct button_checker_gui {
    sfMouseButtonEvent click;
    game_t *game;
    sfEvent *event;
    sfFloatRect bounds;
    gui_button_t *button;
    entity_t *entity;
    sfVector2f pos;
};

bool handle_button_click_events_part2(struct button_checker_gui *checker)
{
    if (checker->event->type == sfEvtMouseButtonReleased)
        checker->button->clicked = false;
    if (checker->event->type == sfEvtMouseButtonPressed
            || checker->event->type == sfEvtMouseButtonReleased) {
        checker->click = checker->event->mouseButton;
        if (checker->click.button == sfMouseLeft
                && sfFloatRect_contains(&checker->bounds,
                    checker->pos.x, checker->pos.y))
            checker->button->clicked = (checker->event->type ==
                    sfEvtMouseButtonPressed);
        if (checker->click.button == sfMouseLeft
                && sfFloatRect_contains(&checker->bounds,
                    checker->pos.x, checker->pos.y)
                && checker->event->type == sfEvtMouseButtonReleased
                && checker->button->is_enabled) {
            checker->button->on_click(checker->game, checker->entity);
            return (true);
        }
    }
    return (false);
}

bool handle_button_click_events(game_t *game, entity_t *entity, sfEvent *event)
{
    gui_button_t *button = entity->instance;
    sfFloatRect bounds = sfText_getGlobalBounds(button->text);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfMouseButtonEvent click = {0};
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(game->window,
            mouse, game->gui_view);

    return (handle_button_click_events_part2(&(struct button_checker_gui){
            click, game, event, bounds, button, entity, pos
        }));
}
