/*
** EPITECH PROJECT, 2020
** mute_button
** File description:
** Entity
*/

#include "stdlib.h"
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
#include "myrpg/parameters.h"

bool create_mute_button(game_t *game UNUSED, entity_t *entity)
{
    mute_button_t *mute_button = ecalloc(sizeof(mute_button_t), 1);
    sfIntRect rect = IRECT(0, 0, 16, 34 / 2);
    sfTexture *texture = create_texture(game, MUTE_BUTTON, NULL);
    sfFont *font = sfFont_createFromFile(FONT);

    D_ASSERT(mute_button, NULL, NULL,  false);
    D_ASSERT(texture, NULL, NULL,  false);
    mute_button->str = sfText_create();
    mute_button->entity = entity;
    mute_button->clock = create_pausable_clock(game);
    mute_button->sprite = create_sprite(texture, NULL);
    sfText_setFont(mute_button->str, font);
    sfSprite_setTextureRect(mute_button->sprite, rect);
    sfSprite_setScale(mute_button->sprite, VEC2F(3, 3));
    entity->instance = mute_button;
    return (true);
}

void destroy_mute_button(game_t *game UNUSED, entity_t *entity)
{
    mute_button_t *mute_button = entity->instance;

    sfSprite_destroy(mute_button->sprite);
    destroy_pausable_clock(mute_button->clock);
    free(mute_button);
}

void update_mute_button(game_t *game UNUSED, entity_t *entity)
{
    mute_button_t *mute_button = entity->instance;
    sfIntRect rect = sfSprite_getTextureRect(mute_button->sprite);
    sfFloatRect text_r = sfText_getGlobalBounds(mute_button->str);

    sfText_setString(mute_button->str, mute_button->text);
    if (mute_button->mute == true) {
        rect.top = rect.height;
        sfSprite_setTextureRect(mute_button->sprite, rect);
    } else {
        rect.top = 0;
        sfSprite_setTextureRect(mute_button->sprite, rect);
    }
    sfText_setPosition(mute_button->str,
        VEC2F(mute_button->entity->pos.x - text_r.width - 5,
            mute_button->entity->pos.y));
    sfSprite_setPosition(mute_button->sprite, entity->pos);
    tick_pausable_clock(mute_button->clock);
}

void draw_mute_button(game_t *game UNUSED, entity_t *entity)
{
    mute_button_t *mute_button = entity->instance;

    sfRenderWindow_drawText(game->window, mute_button->str, NULL);
    sfRenderWindow_drawSprite(game->window, mute_button->sprite, NULL);
}

bool handle_mute_button_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    mute_button_t *mute = entity->instance;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect rect = sfSprite_getGlobalBounds(mute->sprite);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            if (mute->mute == true) {
                mute->mute =  false;
                mute->fonc(game, false);
            } else {
                mute->mute = true;
                mute->fonc(game, true);
            }
    }
    return (false);
}