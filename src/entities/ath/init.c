/*
** EPITECH PROJECT, 2021
** init
** File description:
** ath
*/

#include "distract/def.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/window.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "myrpg/asset.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/define.h"
#include "stdlib.h"
#include "distract/util.h"
#include "myrpg/cinema.h"

static bool create_ath_buttons(ath_t *ath, game_t *game,
    sfTexture *icon_texture)
{
    int pos_y = 150;

    for (unsigned int i = 0; i < 6; i++) {
        icon_texture  = create_texture(game, ATH_ICON[i],
            &IRECT(0, 0, ICON_RECT, ICON_RECT));
        if (icon_texture == NULL)
            return (false);
        ath->button_sprite[i] = create_sprite(icon_texture, &IRECT(0, 0,
            ICON_RECT, ICON_RECT));
        if (ath->button_sprite[i] == NULL)
            return (false);
        SET_SPRITE_POS(ath->button_sprite[i], VEC2F(WINDOW_W /1.06 , pos_y));
        pos_y += 110;
    }
    return (true);
}
static bool create_ath_stones(ath_t *ath, game_t *game,
    sfTexture *icon_texture)
{
    for (unsigned int i = 0; i < 3; i++) {
        icon_texture = create_texture(game, ATH_STONES[i], NULL);
        if (icon_texture == NULL)
            return (false);
        ath->ath_stones[i] = create_sprite(icon_texture, NULL);
        if (ath->ath_stones[i] == NULL)
            return (false);
        sfSprite_setScale(ath->ath_stones[i], VEC2F(0.5f, 0.5f));
        sfSprite_setPosition(ath->ath_stones[i],
            VEC2F(RECT_ATH_GAME[i].left, RECT_ATH_GAME[i].top));
    }
    return (true);
}

bool create_ath_second_part(ath_t *ath, game_t *game,
    sfTexture *icon_texture)
{
    return (create_ath_buttons(ath, game, icon_texture) &&
            create_ath_stones(ath, game, icon_texture));
}