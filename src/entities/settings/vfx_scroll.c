/*
** EPITECH PROJECT, 2020
** vfx_scroll
** File description:
** Entity
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/parameters.h"


bool create_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = malloc(sizeof(vfx_scroll_t) * 1);
    sfTexture *texture = create_texture(game, ASSET_BAR, NULL);
    sfFont *font = sfFont_createFromFile(FONT);

    vfx_scroll->sprite_bar = create_sprite(texture, NULL);
    texture = create_texture(game, ASSET_SC, NULL);
    vfx_scroll->scrolin = create_sprite(texture, NULL);
    vfx_scroll->entity = entity;
    vfx_scroll->clock = create_pausable_clock(game);
    vfx_scroll->text = sfText_create();
    sfText_setCharacterSize(vfx_scroll->text, 35);
    sfText_setFillColor(vfx_scroll->text, sfWhite);
    sfText_setFont(vfx_scroll->text, font);
    vfx_scroll->on_scroll = NULL;
    vfx_scroll->percentage = 1.0f;
    sfSprite_setScale(vfx_scroll->sprite_bar, VEC2F(10, 5));
    sfSprite_setScale(vfx_scroll->scrolin, VEC2F(5, 5));
    entity->instance = vfx_scroll;
    return (true);
}

void destroy_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;

    sfSprite_destroy(vfx_scroll->sprite_bar);
    sfSprite_destroy(vfx_scroll->scrolin);
    destroy_pausable_clock(vfx_scroll->clock);
    sfText_destroy(vfx_scroll->text);
    free(vfx_scroll);
}

void update_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;
    sfFloatRect pos = sfSprite_getGlobalBounds(vfx_scroll->sprite_bar);

    sfText_setPosition(vfx_scroll->text, VEC2F(pos.left, pos.top -
        (pos.height / 2)));
    tick_pausable_clock(vfx_scroll->clock);
}

void draw_vfx_scroll(game_t *game UNUSED, entity_t *entity)
{
    vfx_scroll_t *vfx_scroll = entity->instance;

    sfRenderWindow_drawSprite(game->window, vfx_scroll->sprite_bar, NULL);
    sfRenderWindow_drawSprite(game->window, vfx_scroll->scrolin, NULL);
    sfRenderWindow_drawText(game->window, vfx_scroll->text, NULL);
}

bool handle_vfx_scroll_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    vfx_scroll_t *vfx_scroll = entity->instance;
    sfFloatRect scrollin = sfSprite_getGlobalBounds(vfx_scroll->sprite_bar);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);

    scrollin.left = scrollin.left + 100;
    scrollin.width = scrollin.width - 160;
    if (sfFloatRect_contains(&scrollin, mouse.x, mouse.y)) {
        return (fonc_scroll_vfx(game, entity));
    }
    return (false);
}
