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
#include "myrpg/state.h"
#include "stdlib.h"
#include <stdio.h>

static void change_vfx(vfx_scroll_t *vfx_scroll,
    sfFloatRect bar, sfFloatRect pos)
{
    vfx_scroll->percentage = (((pos.left - bar.left) *
        100 / bar.width) / 100);
    vfx_scroll->percentage = (vfx_scroll->percentage <= 0) ?
        0.0f : vfx_scroll->percentage;
    vfx_scroll->percentage = (vfx_scroll->percentage >= 1) ?
        1.0f : vfx_scroll->percentage;
}

bool fonc_scroll_vfx(game_t *game UNUSED, entity_t *entity UNUSED)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    vfx_scroll_t *scrl = entity->instance;
    sfFloatRect bar = sfSprite_getGlobalBounds(scrl->sprite_bar);
    sfFloatRect pos = sfSprite_getGlobalBounds(scrl->scrolin);

    bar.left = bar.left + 100;
    bar.width = bar.width - 200;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (scrl->on_scroll != NULL)
            scrl->on_scroll(game, scrl);
        change_vfx(scrl, bar, pos);
        sfSprite_setPosition(scrl->scrolin, VEC2F(mouse.x - (pos.width / 2),
                bar.top - (pos.height / 2) + bar.height / 2));
        if (scrl->on_scroll != NULL)
            scrl->on_scroll(game, scrl);
        return (true);
    }
    return false;
}