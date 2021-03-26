/*
** EPITECH PROJECT, 2020
** setting_button
** File description:
** Entity
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/scenes.h"
#include "stdlib.h"
#include <stdio.h>

void create_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = malloc(sizeof(settings_t));
    sfTexture *texture =
        create_texture(game, MAIN_MENU_BG, &MENU_BG_RECT(window));

    setting_button->background = create_sprite(texture, NULL);
    texture = create_texture(game, "asset/setting/bar.png", NULL);
    setting_button->bar_vfx = create_sprite(texture, NULL);
    sfSprite_setScale(setting_button->bar_vfx, VEC2F(2, 2));
    setting_button->entity = entity;
    sfSprite_setPosition(setting_button->bar_vfx, VEC2F(500, 500));
    setting_button->clock = create_pausable_clock(game);
    load_button(game, texture, setting_button);
    texture = create_texture(game, "asset/setting/scroll.png", NULL);
    setting_button->sprite_button[2] = create_sprite(texture, NULL);
    sfSprite_setPosition(setting_button->sprite_button[2],
        sfSprite_getPosition(setting_button->bar_vfx));
    sfSprite_setScale(setting_button->sprite_button[2], VEC2F(2, 2));
    entity->instance = setting_button;
}

void destroy_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfSprite_destroy(setting_button->background);
    destroy_pausable_clock(setting_button->clock);
    free(setting_button);
}

void update_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;
    sfFloatRect pos_vfx = sfSprite_getGlobalBounds(setting_button->bar_vfx);
    sfVector2f pos_sc_vfx = sfSprite_getPosition(
                                setting_button->sprite_button[2]);
    (void)pos_vfx;
    (void)pos_sc_vfx;
    sfSprite_setPosition(setting_button->sprite_button[1], VEC2F(300, 300));
    sfSprite_setPosition(setting_button->bar_vfx, VEC2F(500, 500));
    tick_pausable_clock(setting_button->clock);
}

void draw_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfRenderWindow_drawSprite(game->window, setting_button->background, NULL);
    DRAW_SPRITE(game->window, setting_button->bar_vfx, NULL);
    for (int i = 0; i <= 2; i++) {
        sfRenderWindow_drawSprite(game->window,
            setting_button->sprite_button[i], NULL);
    }
}

bool handle_settings_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    settings_t *button = entity->instance;
    sfFloatRect pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    parameters_t *params = {0};

    for (int i = 0; i <= 2; i++) {
        pos = sfSprite_getGlobalBounds(button->sprite_button[i]);
        if (sfFloatRect_contains(&pos, mouse.x, mouse.y)) {
            sfSprite_setScale(button->sprite_button[i], VEC2F(0.5 , 0.5));
            sfSprite_setScale(button->sprite_button[2], VEC2F(2, 2));
            return (function_button_settings(game, i, params,  entity));
        } else {
            sfSprite_setScale(button->sprite_button[i], VEC2F(0.3 , 0.3));
            sfSprite_setScale(button->sprite_button[2], VEC2F(2, 2));
        }
    }
    return (false);
}