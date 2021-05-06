/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** create_button
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

bool init_btn_pause(game_t *game, entity_t *entity)
{
    pause_menu_t *pause = entity->instance;
    sfIntRect rect = (sfIntRect){0, 0, 64, 33};
    sfTexture *texture = create_texture(game, BACK_BUTTON, NULL);
    sfFloatRect pos = sfSprite_getGlobalBounds(pause->sprite);

    D_ASSERT(texture, NULL, "error texture", false);
    for (int index = 0; index != 3; index++) {
        pause->btn[index] = create_sprite(texture, NULL);
        D_ASSERT(pause->btn[index], NULL, "error sprite btn", false);
        sfSprite_setTextureRect(pause->btn[index], rect);
        sfSprite_setScale(pause->btn[index], VEC2F(4, 4));
        sfSprite_setPosition(pause->btn[index],
            VEC2F(WINDOW_W / 3 + ((pos.width / 2) - (32 * 4)),
                WINDOW_H / 6 + (WINDOW_H / 6)  + ((33 * 4) * index) + 10));
    }
    return (true);
}

bool loop_create(game_t *game UNUSED, pause_menu_t *pause, sfFont *font)
{
    sfFloatRect rect;

    for (int index = 0; index != 3; index++) {
        rect = sfSprite_getGlobalBounds(pause->btn[index]);
        pause->str[index] = sfText_create();
        D_ASSERT(pause->str[index], NULL, "error create texte pause", false);
        sfText_setFont(pause->str[index], font);
        sfText_setPosition(pause->str[index],
            VEC2F(rect.left + (rect.width / 3), rect.top + (rect.height / 3)));
    }
    return (true);
}

bool init_text_pause(game_t *game, entity_t *entity)
{
    pause_menu_t *pause = entity->instance;
    sfFont *font = create_font(game, FONT);

    pause->title = sfText_create();
    D_ASSERT(pause->title, NULL, "error create title pause", false);
    D_ASSERT(font, NULL, "error create font texte", false);
    D_ASSERT(loop_create(game, pause, font), false, "error", false);
    sfText_setFont(pause->title, font);
    sfText_setString(pause->title, "Pause");
    sfText_setString(pause->str[0], "continue");
    sfText_setString(pause->str[1], "menu");
    sfText_setString(pause->str[2], "exit");
    return (true);
}