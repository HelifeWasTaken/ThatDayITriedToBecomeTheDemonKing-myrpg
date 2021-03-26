/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** create_menu.c
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

static void create_background(game_t *game UNUSED,
    menu_t *menu)
{
    sfTexture *menu_texture =
        create_texture(game, MAIN_MENU_BG, &MENU_BG_RECT(window));
    sfTexture *button_texture;
    int pos_y = 3;

    menu->bg_sprite = create_sprite(menu_texture, NULL);
    for (int i = 0; i < 3; i++) {
        button_texture = create_texture(game, ASSET_MENU_PATH[i],
            &MENU_BUTTON_RECT);
        menu->button_sprite[i] = create_sprite(button_texture, NULL);
        SET_SPRITE_POS(menu->button_sprite[i], VEC2F(WINDOW_W/2,
            BUTTON_MENU_POS[i]));
        pos_y--;
    }
}

void create_menu(game_t *game UNUSED, entity_t *entity)
{
    menu_t *menu = malloc(sizeof(menu_t));

    create_background(game, menu);
    entity->instance = menu;
}