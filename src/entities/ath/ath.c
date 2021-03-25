/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** ath.c
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/window.h"
#include "SFML/Window.h"
#include "myrpg/asset.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/define.h"
#include "stdlib.h"

bool handle_ath_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    ath_t *ath = entity->instance;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect buton_pos;

    for (int i = 0; i < 6; i++) {
        buton_pos = sfSprite_getGlobalBounds(ath->button_sprite[i]);
        if (sfFloatRect_contains(&buton_pos, mouse_pos.x,
            mouse_pos.y) == sfTrue) {
            sfSprite_setScale(ath->button_sprite[i], VEC2F(1.2, 1.2));
            return (true);
        } else
            sfSprite_setScale(ath->button_sprite[i], VEC2F(1, 1));
    }
    return (false);
}

void create_ath(game_t *game UNUSED, entity_t *entity)
{
    ath_t *ath = malloc(sizeof(ath_t));
    sfTexture *icon_texture;
    int pos_y = 150;
    sfTexture *player_ath_texture = create_texture(game, PLAYER_ATH,
        &IRECT(0, 0, PLAYER_ATH_W, PLAYER_ATH_H));

    ath->player_ath_sprite = create_sprite(player_ath_texture,
        &IRECT(0, 0, PLAYER_ATH_W, PLAYER_ATH_H));
    SET_SPRITE_POS(ath->player_ath_sprite, VEC2F(0, PLAYER_ATH_POS_Y));
    for (int i = 0; i < 6; i++) {
        icon_texture  = create_texture(game, ATH_ICON[i],
            &IRECT(0, 0, ICON_RECT, ICON_RECT));
        ath->button_sprite[i] = create_sprite(icon_texture, &IRECT(0, 0, ICON_RECT, ICON_RECT));
        SET_SPRITE_POS(ath->button_sprite[i], VEC2F(1810, pos_y));
        pos_y += 110;
    }
    entity->instance = ath;
}

void draw_ath(game_t *game UNUSED, entity_t *entity)
{
    ath_t *ath = entity->instance;

    DRAW_SPRITE(game->window, ath->player_ath_sprite, NULL);
    for (int i = 0; i < 6; i++)
        DRAW_SPRITE(game->window, ath->button_sprite[i], NULL);
}

void destroy_ath(game_t *game UNUSED, entity_t *entity)
{
    ath_t *ath = entity->instance;

    for (int i = 0; i < 6; i++)
        sfSprite_destroy(ath->button_sprite[i]);
    sfSprite_destroy(ath->player_ath_sprite);
    free(ath);
}