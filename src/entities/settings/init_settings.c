/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_settings
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
#include "myrpg/define.h"
#include "stdlib.h"
#include <stdio.h>

sfSprite *init_bkbtn(game_t *game, entity_t * entity)
{
    sfTexture *texture = create_texture(game, BACK_BUTTON, NULL);
    sfSprite *sprite = NULL;

    D_ASSERT(texture, NULL, "error text button", NULL);
    sprite = create_sprite(texture, NULL);
    D_ASSERT(sprite, NULL, "error sprite backbutton", NULL);
    return (sprite);
}

sfSprite *init_background(game_t *game, entity_t *entity)
{
    sfTexture *texture = create_texture(game, MAIN_MENU_BG, &MENU_BG_RECT);
    sfSprite *sprite = NULL;

    D_ASSERT(texture, NULL, "error texture background", NULL);
    sprite = create_sprite(texture, NULL);
    D_ASSERT(sprite, NULL, "error sprite bg", NULL);
    return (sprite);
}

sfText *init_text(game_t *game, entity_t *entity)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);

    D_ASSERT(font, NULL, "error font", NULL);
    D_ASSERT(text, NULL, "error text", NULL);
    sfText_setFont(text, font);
    sfText_setString(text, "BACK");
    sfText_setCharacterSize(text, 40);
    return (text);
}