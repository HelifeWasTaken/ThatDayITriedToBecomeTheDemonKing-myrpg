/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu.c
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/window.h"
#include "SFML/Window.h"
#include "myrpg/asset.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "stdlib.h"

bool handle_menu_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    menu_t *menu = entity->instance;
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfFloatRect buton_pos;

    for (int i = 0; i < 3; i++) {
        buton_pos = sfSprite_getGlobalBounds(menu->buton_sprite[i]);
        if (sfFloatRect_contains(&buton_pos, mouse_pos.x ,
            mouse_pos.y) == sfTrue) {
            sfSprite_setScale(menu->buton_sprite[i], VEC2F(1.5, 1.5));
            return (true);
        } else
            sfSprite_setScale(menu->buton_sprite[i], VEC2F(1, 1));
    }
    return (false);
}

void draw_menu(game_t *game UNUSED, entity_t *entity)
{
    menu_t *menu = entity->instance;

    DRAW_SPRITE(game->window, menu->bg_sprite, NULL);
    for (int i = 0; i < 3; i++)
        DRAW_SPRITE(game->window, menu->buton_sprite[i], NULL);
}

void destroy_menu(game_t *game UNUSED, entity_t *entity)
{
    menu_t *menu = entity->instance;

    sfSprite_destroy(menu->bg_sprite);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(menu->buton_sprite[i]);
    free(menu);
}