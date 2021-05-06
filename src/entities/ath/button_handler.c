/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_handler
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

bool func_btn_coin(UNUSED game_t *game, UNUSED entity_t *entity)
{
    return (false);
}

void function_handler(game_t *game, UNUSED entity_t *entity, int i)
{
    function_ath_btn_t tab[4] = {
        {&func_btn_quest},
        {&func_btn_inventory},
        {&func_btn_save},
        {&func_btn_setting}
    };
    tab[i].func(game, entity);
}

void update_button_handler(game_t *game UNUSED, entity_t *entity)
{
    ath_t *ath = entity->instance;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect buton_pos;

    for (int i = 0; i < 4; i++) {
        buton_pos = sfSprite_getGlobalBounds(ath->button_sprite[i]);
        if (sfFloatRect_contains(&buton_pos, mouse_pos.x,
            mouse_pos.y) == sfTrue) {
            sfSprite_setScale(ath->button_sprite[i], VEC2F(1.2, 1.2));
        } else
            sfSprite_setScale(ath->button_sprite[i], VEC2F(1, 1));
    }
}