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
#include "distract/debug.h"
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

    D_ASSERT(setting_button, NULL, "error malloc setting btn", false);
    setting_button->background = init_background(game, entity);
    D_ASSERT(setting_button->background, NULL, "error", false);
    setting_button->ground = init_ground(game, entity);
    D_ASSERT(setting_button->ground, NULL, "error ground", false);
    setting_button->txt = init_text_btn(game, entity);
    D_ASSERT(setting_button->txt, NULL, "err", false);
    setting_button->entity = entity;
    setting_button->clock = create_pausable_clock(game);
    D_ASSERT(setting_button->clock, NULL, "erro clock setting", false);
    load_button(game, setting_button);
    D_ASSERT(setting_button->sprite_button, NULL, "error spr bt back", false);
    set_size_sett(setting_button);
    entity->instance = setting_button;
    return (true);
}

void destroy_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfSprite_destroy(setting_button->background);
    sfSprite_destroy(setting_button->ground);
    sfSprite_destroy(setting_button->sprite_button);
    sfText_destroy(setting_button->txt);
    destroy_pausable_clock(setting_button->clock);
    free(setting_button);
}

void update_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;
    sfFloatRect pos = sfSprite_getGlobalBounds(setting_button->sprite_button);

    sfSprite_setPosition(setting_button->sprite_button, VEC2F(300, 300));
    sfText_setPosition(setting_button->txt,
        VEC2F(pos.left + (pos.width / 4) + 10,
            pos.top + (pos.height / 4) - 10));
    tick_pausable_clock(setting_button->clock);
}

void draw_settings(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfRenderWindow_drawSprite(game->window, setting_button->background, NULL);
    sfRenderWindow_drawSprite(game->window, setting_button->ground, NULL);
    sfRenderWindow_drawSprite(game->window,
                setting_button->sprite_button, NULL);
    sfRenderWindow_drawText(game->window, setting_button->txt, NULL);
}

bool handle_settings_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    settings_t *button = entity->instance;
    sfFloatRect pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    pos = sfSprite_getGlobalBounds(button->sprite_button);
    if (sfFloatRect_contains(&pos, mouse.x, mouse.y)) {
        sfSprite_setScale(button->sprite_button, VEC2F(4, 4));
        sfText_setScale(button->txt, VEC2F(1.5, 1.5));
        sfText_setColor(button->txt, sfColor_fromRGB(255, 0, 0));
        return (function_button_settings(game, 0, entity));
    } else {
        sfText_setScale(button->txt, VEC2F(1, 1));
        sfSprite_setScale(button->sprite_button, VEC2F(3, 3));
        sfText_setColor(button->txt, sfColor_fromRGB(255, 255, 255));
    }
    return (false);
}
