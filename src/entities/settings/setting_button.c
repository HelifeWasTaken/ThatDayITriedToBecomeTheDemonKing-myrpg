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
#include "myrpg/state.h"
#include "stdlib.h"
#include <stdio.h>

bool create_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = malloc(sizeof(settings_t));
    sfTexture *texture =
        create_texture(game, MAIN_MENU_BG, &MENU_BG_RECT(window));
    sfFloatRect size;

    setting_button->background = create_sprite(texture, NULL);
    texture = create_texture(game, SET_BACK, NULL);
    setting_button->ground = create_sprite(texture, NULL);
    size = sfSprite_getGlobalBounds(setting_button->ground);
    sfSprite_setScale(setting_button->ground, VEC2F(WINDOW_W / size.width,
        WINDOW_H / size.height));
    setting_button->entity = entity;
    setting_button->clock = create_pausable_clock(game);
    load_button(game, texture, setting_button);
    entity->instance = setting_button;
    return (true);
}

void destroy_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfSprite_destroy(setting_button->background);
    sfSprite_destroy(setting_button->ground);
    destroy_pausable_clock(setting_button->clock);
    free(setting_button);
}

void update_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;
    game_state_t *param = game->state;

    (void)param;
    sfSprite_setPosition(setting_button->sprite_button[1], VEC2F(300, 300));
    tick_pausable_clock(setting_button->clock);
}

void draw_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfRenderWindow_drawSprite(game->window, setting_button->background, NULL);
    sfRenderWindow_drawSprite(game->window, setting_button->ground, NULL);
    for (int i = 0; i <= 1; i++) {
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
    game_state_t *state = game->state;

    for (int i = 0; i <= 2; i++) {
        pos = sfSprite_getGlobalBounds(button->sprite_button[i]);
        if (sfFloatRect_contains(&pos, mouse.x, mouse.y)) {
            sfSprite_setScale(button->sprite_button[i], VEC2F(4, 4));
            sfSprite_setScale(button->sprite_button[2], VEC2F(2, 2));
            return (function_button_settings(game, i, &state->params,  entity));
        } else {
            sfSprite_setScale(button->sprite_button[i], VEC2F(3, 3));
            sfSprite_setScale(button->sprite_button[2], VEC2F(2, 2));
        }
    }
    return (false);
}
