/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_scroll
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
#include "stdlib.h"
#include <stdio.h>

sfSprite *init_scroll(game_t *game, UNUSED entity_t *entity)
{
    sfTexture *texture = create_texture(game, ASSET_BAR, NULL);
    sfSprite *sprite = NULL;

    (void)game;
    D_ASSERT(texture, NULL, "fail scrollbar", NULL);
    sprite = create_sprite(texture, NULL);
    D_ASSERT(sprite, NULL, "fail scrollbar2", NULL);
    sfSprite_setScale(sprite, VEC2F(10, 5));
    return (sprite);
}

sfSprite *init_scrolin(game_t *game)
{
    sfTexture *texture = create_texture(game, ASSET_SC, NULL);
    sfSprite *sprite = NULL;

    (void)game;
    D_ASSERT(texture, NULL, "fail scrolin", NULL);
    sprite = create_sprite(texture, NULL);
    D_ASSERT(sprite, NULL, "fail scrolin2", NULL);
    sfSprite_setScale(sprite, VEC2F(5, 5));
    return (sprite);
}

sfText *init_text(UNUSED game_t *game, UNUSED entity_t *entity)
{
    sfFont *font = sfFont_createFromFile(FONT);
    sfText *text = sfText_create();

    D_ASSERT(text, NULL, "fail text", false);
    D_ASSERT(font, NULL, "fail font", false);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setFillColor(text, sfWhite);
    return (text);
}