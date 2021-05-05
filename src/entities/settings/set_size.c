/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** set_size
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

void set_size_vox(game_t *game, vfx_scroll_t *scroll)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(scroll->scrolin);
    sfFloatRect bar = sfSprite_getGlobalBounds(scroll->sprite_bar);
    game_state_t *state = game->state;

    bar.left += 100;
    bar.width -= 200;
    sfSprite_setPosition(scroll->scrolin,
    VEC2F(bar.left + (state->params.voice_vol * bar.width) - (pos.width/2),
    bar.top - (pos.height / 2) + bar.height / 2));
}

void set_size_vfx(game_t *game, vfx_scroll_t *scroll)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(scroll->scrolin);
    sfFloatRect bar = sfSprite_getGlobalBounds(scroll->sprite_bar);
    game_state_t *state = game->state;

    bar.left += 100;
    bar.width -= 200;
    sfSprite_setPosition(scroll->scrolin,
    VEC2F(bar.left + (state->params.vfx_vol * bar.width) - (pos.width / 2),
    bar.top - (pos.height / 2) + bar.height / 2));
}

void set_size_mus(game_t *game, vfx_scroll_t *scroll)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(scroll->scrolin);
    sfFloatRect bar = sfSprite_getGlobalBounds(scroll->sprite_bar);
    game_state_t *state = game->state;

    bar.left += 100;
    bar.width -= 200;
    sfSprite_setPosition(scroll->scrolin,
    VEC2F(bar.left + (state->params.music_vol * bar.width) - (pos.width/2),
        bar.top - (pos.height / 2) + bar.height / 2));
}

void set_size_sett(settings_t * setting)
{
    sfFloatRect pos;

    pos = sfSprite_getGlobalBounds(setting->ground);
    sfSprite_setScale(setting->ground, VEC2F(WINDOW_W / pos.width,
        WINDOW_H / pos.height));
    pos = sfSprite_getGlobalBounds(setting->sprite_button);
    sfSprite_setTextureRect(setting->sprite_button, (sfIntRect)
        { 0, 0, pos.width, pos.height / 2});
}