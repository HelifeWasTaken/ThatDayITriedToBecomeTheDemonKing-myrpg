/*
** EPITECH PROJECT, 2020
** quest_menu
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

bool create_quest_menu(game_t *game UNUSED, entity_t *entity)
{
    quest_menu_t *quest_menu = dcalloc(sizeof(quest_menu_t), 1);
    sfTexture *texture = create_texture(game, SET_BACK, NULL);

    D_ASSERT(quest_menu, NULL, "", false)
    D_ASSERT(texture, NULL, "error create quest texture", false);
    quest_menu->entity = entity;
    quest_menu->clock = create_pausable_clock(game);
    D_ASSERT(quest_menu->clock, NULL, "error clock", false);
    quest_menu->sprite = create_sprite(texture, NULL);
    D_ASSERT(quest_menu->sprite, NULL, "error sprite menu", false);
    quest_menu->entity->draw_on_gui = true;
    quest_menu->entity->z = 10000;
    entity->pos = VEC2F(WINDOW_W / 3, WINDOW_H / 6);
    quest_menu->is_display = false;
    entity->instance = quest_menu;
    D_ASSERT(create_text_quest(game, entity), false, "", false);
    return (true);
}

void destroy_quest_menu(game_t *game UNUSED, entity_t *entity)
{
    quest_menu_t *quest_menu = entity->instance;

    sfSprite_destroy(quest_menu->sprite);
    destroy_pausable_clock(quest_menu->clock);
    free(quest_menu);
}

void update_quest_menu(game_t *game UNUSED, entity_t *entity)
{
    quest_menu_t *quest_menu = entity->instance;
    sfFloatRect rect = sfText_getGlobalBounds(quest_menu->back);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
        sfText_setColor(quest_menu->back, sfRed);
    } else {
        sfText_setColor(quest_menu->back, sfWhite);
    }
    sfSprite_setPosition(quest_menu->sprite, entity->pos);
    tick_pausable_clock(quest_menu->clock);
}

void draw_quest_menu(game_t *game UNUSED, entity_t *entity)
{
    quest_menu_t *quest_menu = entity->instance;

    if (quest_menu->is_display == true) {
        sfRenderWindow_drawSprite(game->window, quest_menu->sprite, NULL);
        sfRenderWindow_drawText(game->window, quest_menu->back, NULL);
        sfRenderWindow_drawText(game->window, quest_menu->text, NULL);
    }
}

bool handle_quest_menu_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    quest_menu_t *quest = entity->instance;
    sfFloatRect rect = sfText_getGlobalBounds(quest->back);
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    if (sfFloatRect_contains(&rect, pos.x, pos.y)
        && quest->is_display == true && sfMouse_isButtonPressed(sfMouseLeft)) {
            quest->is_display = !(quest->is_display);
    }
    return (false);
}