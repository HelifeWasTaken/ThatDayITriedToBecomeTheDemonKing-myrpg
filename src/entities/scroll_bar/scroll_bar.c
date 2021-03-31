/*
** EPITECH PROJECT, 2020
** scroll_bar
** File description:
** Entity
*/

#include <distract/game.h>
#include <distract/entity.h>
#include <distract/resources.h>
#include <distract/graphics.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <myrpg/entities.h>
#include <stdlib.h>
#include <stdio.h>

bool create_scroll_bar(game_t *game UNUSED, entity_t *entity)
{
    scroll_bar_t *scroll_bar = malloc(sizeof(scroll_bar_t) * 1);

    if (scroll_bar == NULL)
        return (false);
    scroll_bar->entity = entity;
    if ((scroll_bar->clock = create_pausable_clock(game)) == NULL)
        return (false);
    if ((scroll_bar->scroll_bar = sfRectangleShape_create()) == NULL)
        return (false);
    sfRectangleShape_setSize(scroll_bar->scroll_bar,
        (sfVector2f){game->mode.width * 0.015, game->mode.height * 0.10});
    sfRectangleShape_setFillColor(scroll_bar->scroll_bar, sfRed);
    scroll_bar->entity->pos.x = game->mode.width + 50;
    scroll_bar->entity->pos.y = 0;
    entity->instance = scroll_bar;
    return (true);
}

void destroy_scroll_bar(game_t *game UNUSED, entity_t *entity)
{
    scroll_bar_t *scroll_bar = entity->instance;

    sfRectangleShape_destroy(scroll_bar->scroll_bar);
    destroy_pausable_clock(scroll_bar->clock);
    free(scroll_bar);
}

void update_scroll_bar(game_t *game UNUSED, entity_t *entity)
{
    scroll_bar_t *scroll_bar = entity->instance;

    sfRectangleShape_setPosition(scroll_bar->scroll_bar, entity->pos);
    tick_pausable_clock(scroll_bar->clock);
}

void draw_scroll_bar(game_t *game UNUSED, entity_t *entity)
{
    scroll_bar_t *scroll_bar = entity->instance;

    sfRenderWindow_drawRectangleShape(game->window,
        scroll_bar->scroll_bar, NULL);
}

bool handle_scroll_bar_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    scroll_bar_t *scroll = entity->instance;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect scroll_r = sfRectangleShape_getGlobalBounds(scroll->scroll_bar);

    if (sfFloatRect_contains(&scroll_r, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            entity->pos = VEC2F(entity->pos.x, mouse.y -
                (scroll_r.height / 2) + 10);
    }
    return (false);
}