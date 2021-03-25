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

void create_setting_button(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = my_calloc(sizeof(settings_t), 1);
    sfIntRect rect = IRECT(0, 0, 9133, 379);
    sfTexture *texture = create_texture(game, "background.png", &rect);

    setting_button->entity = entity;
    setting_button->clock = create_pausable_clock(game);
    setting_button->sprite[1] = create_sprite(texture, NULL);
    entity->instance = setting_button;
}

void destroy_setting_button(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfSprite_destroy(setting_button->sprite);
    destroy_pausable_clock(setting_button->clock);
    free(setting_button);
}

void update_setting_button(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfSprite_setPosition(setting_button->sprite, entity->pos);
    tick_pausable_clock(setting_button->clock);
}

void draw_setting_button(game_t *game UNUSED, entity_t *entity)
{
    settings_t *setting_button = entity->instance;

    sfRenderWindow_drawSprite(game->window, setting_button->sprite, NULL);
}

bool handle_setting_button_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    return (false);
}