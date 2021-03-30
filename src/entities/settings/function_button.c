/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function_button
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
#include "myrpg/parameters.h"
#include "stdlib.h"
#include <stdio.h>


void vfx_scrolin(game_t *game UNUSED,
    parameters_t *parm UNUSED, entity_t *entity UNUSED)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    vfx_scroll_t *sc = entity->instance;
    sfFloatRect bar = sfSprite_getGlobalBounds(sc->sprite_bar);
    sfVector2f pos = sfSprite_getPosition(sc->scrolin);

    if (sfMouse_isButtonPressed(sfMouseLeft)
        && bar.left + 1 <= mouse.x &&  bar.left + bar.width >= mouse.x)
        sfSprite_setPosition(sc->scrolin,
            VEC2F(mouse.x - 20, pos.y));
    return;
}


void load_button(game_t *game, sfTexture *texture, settings_t *setting_button)
{
    for (int i = 0; i <= 3; i++) {
        texture = create_texture(game, ASSET_SETTING_PATH[i], NULL);
        setting_button->sprite_button[i] = create_sprite(texture, NULL);
        sfSprite_setScale(setting_button->sprite_button[i], VEC2F(0.3, 0.3));
    }
}

bool function_button_settings(game_t *game, int i,
    parameters_t *param UNUSED, entity_t *entity UNUSED)
{
    if (i == 0 && sfMouse_isButtonPressed(sfMouseLeft)) {
        switch_to_scene(game, MENU_SCENE);
        return (true);
    }
    return (false);
}