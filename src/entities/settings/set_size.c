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
#include "stdlib.h"
#include <stdio.h>

void set_size_vox(game_t *game, vfx_scroll_t *scroll)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(scroll->scrolin);
    sfFloatRect bar = sfSprite_getGlobalBounds(scroll->sprite_bar);
    parameters_t *param = game->state;

    bar.left += 100;
    bar.width -= 200;
    sfSprite_setPosition(scroll->scrolin,
        VEC2F(bar.left + (param->voice_vol * bar.width) - (pos.width / 2),
            bar.top - (pos.height / 2) + bar.height / 2));
}

void set_size_vfx(game_t *game, vfx_scroll_t *scroll)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(scroll->scrolin);
    sfFloatRect bar = sfSprite_getGlobalBounds(scroll->sprite_bar);
    parameters_t *param = game->state;

    bar.left += 100;
    bar.width -= 200;
    sfSprite_setPosition(scroll->scrolin,
        VEC2F(bar.left + (param->vfx_vol * bar.width) - (pos.width / 2),
            bar.top - (pos.height / 2) + bar.height / 2));
}

void set_size_mus(game_t *game, vfx_scroll_t *scroll)
{
    sfFloatRect pos = sfSprite_getGlobalBounds(scroll->scrolin);
    sfFloatRect bar = sfSprite_getGlobalBounds(scroll->sprite_bar);
    parameters_t *param = game->state;

    bar.left += 100;
    bar.width -= 200;
    sfSprite_setPosition(scroll->scrolin,
        VEC2F(bar.left + (param->music_vol * bar.width) - (pos.width / 2),
            bar.top - (pos.height / 2) + bar.height / 2));
}

