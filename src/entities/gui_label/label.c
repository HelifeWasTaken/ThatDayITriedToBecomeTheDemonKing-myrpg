/*
** EPITECH PROJECT, 2020
** label
** File description:
** Entity
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "distract/util.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"

bool create_label(game_t *game UNUSED, entity_t *entity)
{
    gui_label_t *label = dcalloc(sizeof(gui_label_t), 1);
    sfFont *font = create_font(game, "asset/04b_19.ttf");

    D_ASSERT(label, NULL, "Could not create label", false)
    label->entity = entity;
    label->text = sfText_create();
    label->is_enabled = true;
    D_ASSERT(label->text, NULL, "Could not create label text", false)
    sfText_setFont(label->text, font);
    entity->instance = label;
    entity->z = 10000;
    entity->draw_on_gui = true;
    return (true);
}

void destroy_label(game_t *game UNUSED, entity_t *entity)
{
    gui_label_t *label = entity->instance;

    sfText_destroy(label->text);
    free(label);
}

void update_label(game_t *game UNUSED, entity_t *entity)
{
    gui_label_t *label = entity->instance;

    sfText_setString(label->text, label->title);
    sfText_setPosition(label->text, entity->pos);
}

void draw_label(game_t *game UNUSED, entity_t *entity)
{
    gui_label_t *label = entity->instance;

    if (label->is_enabled)
        sfRenderWindow_drawText(game->window, label->text, NULL);
}