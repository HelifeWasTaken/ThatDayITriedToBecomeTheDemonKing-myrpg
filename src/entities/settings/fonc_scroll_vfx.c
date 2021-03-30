/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** fonc_scroll_vfx
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

bool fonc_scroll_vfx(game_t *game UNUSED,
entity_t *entity UNUSED)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    vfx_scroll_t *vfx_scroll = entity->instance;
    sfFloatRect bar = sfSprite_getGlobalBounds(vfx_scroll->sprite_bar);
    sfFloatRect pos = sfSprite_getGlobalBounds(vfx_scroll->scrolin);
    parameters_t *param = game->state;

    (void)bar;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        param->vfx_vol = ((((bar.left - pos.left) / 4) / 100) * -1);
        sfSprite_setPosition(vfx_scroll->scrolin, VEC2F(mouse.x - (pos.width / 2), bar.top - (pos.height / 2) + bar.height / 2));
        return (true);
    }





    /*
    if (sfMouse_isButtonPressed(sfMouseLeft)
        && param->vfx_vol >= 0.0 && param->vfx_vol <= 1.95) {
        sfSprite_setPosition(sc->scrolin,
            VEC2F(mouse.x - 10, pos.y));
        return (true);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && pos.x >= 1.95) {
        sfSprite_setPosition(sc->scrolin, VEC2F(pos.x - 10, pos.y));
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && param->vfx_vol <= 0) {
        sfSprite_setPosition(sc->scrolin, VEC2F(bar.left + 2, pos.y));
    }
    */
    return false;
}