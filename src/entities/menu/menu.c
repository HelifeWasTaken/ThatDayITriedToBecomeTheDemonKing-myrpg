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
#include "SFML/Graphics.h"
#include "stdlib.h"
#include "myrpg/entities.h"
#include "myrpg/scenes.h"
#include "myrpg/asset.h"

void button_fonc(game_t *game, int i)
{
    if (i == 0 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        switch_to_scene(game, PLAY_SCENE);
    if (i == 1 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        switch_to_scene(game, SETTING_SCENE);
    if (i == 2 && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        close_game(game);
}

bool handle_menu_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    menu_t *menu = entity->instance;
    sfVector2f mouse_pos = get_mouse_pos(game);
    sfFloatRect buton_pos;

    for (int i = 0; i < 3; i++) {
        buton_pos = sfSprite_getGlobalBounds(menu->button_sprite[i]);
        if (sfFloatRect_contains(&buton_pos, mouse_pos.x,
                    mouse_pos.y) == sfTrue) {
            sfSprite_setScale(menu->button_sprite[i], VEC2F(2, 2));
            button_fonc(game, i);
            return (true);
        } else
            sfSprite_setScale(menu->button_sprite[i], VEC2F(1.5, 1.5));
    }
    return (false);
}

void draw_menu(game_t *game UNUSED, entity_t *entity)
{
    menu_t *menu = entity->instance;

    if (!menu->is_initialized) {
        handle_menu_events(game, entity, NULL);
        menu->is_initialized = false;
    }
    DRAW_SPRITE(game->window, menu->bg_sprite, NULL);
    for (int i = 0; i < 3; i++)
        DRAW_SPRITE(game->window, menu->button_sprite[i], NULL);
}

void destroy_menu(game_t *game UNUSED, entity_t *entity)
{
    menu_t *menu = entity->instance;

    sfSprite_destroy(menu->bg_sprite);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(menu->button_sprite[i]);
    free(menu);
}