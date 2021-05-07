/*
** EPITECH PROJECT, 2020
** pause_menu
** File description:
** Entity
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

bool create_pause_menu(game_t *game UNUSED, entity_t *entity)
{
    pause_menu_t *pause_menu = dcalloc(sizeof(pause_menu_t), 1);
    sfIntRect rect = IRECT(0, 0, 9133, 379);
    sfTexture *texture = create_texture(game, BG_PAUSE, &rect);

    pause_menu->is_display = false;
    D_ASSERT(pause_menu, NULL, "erro malloc pause_menu", false);
    D_ASSERT(texture, NULL, "error pause menu", false);
    pause_menu->entity = entity;
    pause_menu->clock = create_pausable_clock(game);
    D_ASSERT(pause_menu->clock, NULL, "error clock", false);
    pause_menu->sprite = create_sprite(texture, NULL);
    D_ASSERT(pause_menu->sprite, NULL, "error bg pause", false);
    sfSprite_setScale(pause_menu->sprite, VEC2F(1, 4));
    entity->draw_on_gui = true;
    entity->z = 10000;
    entity->instance = pause_menu;
    pause_menu->clock->has_game_pause = sfFalse;
    D_ASSERT(init_btn_pause(game, entity), false, "error:", false);
    D_ASSERT(init_text_pause(game,entity), false, "error:", false);
    return (true);
}

void destroy_pause_menu(game_t *game UNUSED, entity_t *entity)
{
    pause_menu_t *pause_menu = entity->instance;

    sfSprite_destroy(pause_menu->sprite);
    destroy_pausable_clock(pause_menu->clock);
    free(pause_menu);
}

void update_pause_menu(game_t *game UNUSED, entity_t *entity)
{
    pause_menu_t *pause = entity->instance;

    if (pause->is_display == true)
        game->is_paused = true;
    if (IS_KEY_PRESS_FRAME(sfKeyEscape)) {
        pause->is_display = (!pause->is_display);
        game->is_paused = !game->is_paused;
    }
    for (int index = 0; index != 3; index++)
        sfSprite_setTextureRect(pause->btn[index], IRECT(0, 0, 64, 33));
    sfSprite_setPosition(pause->sprite, VEC2F(WINDOW_W / 3, WINDOW_H / 6));
    tick_pausable_clock(pause->clock);
}

void draw_pause_menu(game_t *game UNUSED, entity_t *entity)
{
    pause_menu_t *pause_menu = entity->instance;

    if (pause_menu->is_display == true) {
        game->is_paused = true;
        sfRenderWindow_drawSprite(game->window, pause_menu->sprite, NULL);
        for (int index = 0; index != 3; index++) {
            sfRenderWindow_drawSprite(game->window,
                pause_menu->btn[index], NULL);
            sfRenderWindow_drawText(game->window, pause_menu->str[index], NULL);
        }
    }
}

bool handle_pause_menu_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    pause_menu_t *pause = entity->instance;
    sfVector2i mous = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect rect;

    for (int index = 0; index != 3; index++) {
        rect = sfSprite_getGlobalBounds(pause->btn[index]);
        if (sfFloatRect_contains(&rect, mous.x, mous.y)
            && pause->is_display == true) {
            sfText_setColor(pause->str[index], sfColor_fromRGB(255, 0, 0));
            function_button_pause(game, entity, index);
            return (true);
        } else {
            sfText_setColor(pause->str[index], sfColor_fromRGB(255, 255, 255));
        }
    }
    return (false);
}
