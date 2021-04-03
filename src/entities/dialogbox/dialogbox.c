/*
** EPITECH PROJECT, 2020
** dialogbox
** File description:
** Entity
*/

#include "erty/string/ecstring.h"
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
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>


bool create_dialogbox(game_t *game UNUSED, entity_t *entity)
{
    dialogbox_t *dialogbox = dcalloc(sizeof(dialogbox_t), 1);
    sfIntRect rect = IRECT(0, 0, 216, 216);
    sfTexture *texture = create_texture(game, "asset/collision.png", &rect);
    sfFont *font = create_font(game, "asset/title.ttf");
    entity_t *viewentity = get_entity(game, VIEW);

    D_ASSERT(font, NULL, "Can't get font", false)
    D_ASSERT(viewentity, NULL, "Can't get view", false)
    D_ASSERT(dialogbox, NULL, "Can't create dialog box", false)
    dialogbox->entity = entity;
    dialogbox->clock = create_pausable_clock(game);
    dialogbox->name_text = sfText_create();
    dialogbox->content_text = sfText_create();
    dialogbox->background = sfRectangleShape_create();
    dialogbox->is_visible = false;
    dialogbox->view = viewentity->instance;
    sfText_setColor(dialogbox->name_text, sfBlack);
    sfText_setFont(dialogbox->name_text, font);
    sfText_setColor(dialogbox->content_text, sfBlack);
    sfText_setFont(dialogbox->content_text, font);
    sfRectangleShape_setTexture(dialogbox->background, texture, false);
    sfRectangleShape_setSize(dialogbox->background, VEC2F(1280, 200));
    sfText_setPosition(dialogbox->name_text, VEC2F(120, 110));
    sfText_setPosition(dialogbox->content_text, VEC2F(120, 170));
    sfRectangleShape_setPosition(dialogbox->background, VEC2F(100, 100));
    entity->instance = dialogbox;
    entity->z = 1000000000;
    return (true);
}

void destroy_dialogbox(game_t *game UNUSED, entity_t *entity)
{
    dialogbox_t *dialogbox = entity->instance;

    sfRectangleShape_destroy(dialogbox->background);
    sfText_destroy(dialogbox->name_text);
    sfText_destroy(dialogbox->content_text);
    destroy_pausable_clock(dialogbox->clock);
    free(dialogbox);
}

void update_dialogbox(game_t *game UNUSED, entity_t *entity)
{
    dialogbox_t *dialogbox = entity->instance;
    char *tmp;
    size_t len;

    if (!dialogbox->is_visible)
        return;
    if (!dialogbox->npc) {
        print_error("npc linked to dialogbox not found!");
        return;
    }
    tick_pausable_clock(dialogbox->clock);
    tmp = dialogbox->npc->messages[dialogbox->chunk_id];
    if (dialogbox->clock->time > 0.5) {
        len = estrlen(dialogbox->pending_buffer);
        if (len < estrlen(tmp)) {
            dialogbox->pending_buffer[len] = tmp[len];
            dialogbox->pending_buffer[len + 1] = '\0';
            wrap_dialog_text(dialogbox);
        }
    }
    sfText_setString(dialogbox->name_text, dialogbox->npc->name);
    sfText_setString(dialogbox->content_text, dialogbox->pending_buffer);
}

void draw_dialogbox(game_t *game UNUSED, entity_t *entity)
{
    dialogbox_t *dialogbox = entity->instance;

    if (!dialogbox->is_visible)
        return;
    set_view_type(game, dialogbox->view, HUD_VIEW);
    sfRenderWindow_drawRectangleShape(game->window, dialogbox->background,
        NULL);
    sfRenderWindow_drawText(game->window, dialogbox->name_text, NULL);
    sfRenderWindow_drawText(game->window, dialogbox->content_text, NULL);
    set_view_type(game, dialogbox->view, WORLD_VIEW);
}

bool handle_dialogbox_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    dialogbox_t *dialogbox = entity->instance;
    char *current_msg;
    size_t len;

    if (!dialogbox->is_visible)
        return (false);
    D_ASSERT(dialogbox->npc, NULL, "npc linked to dialogbox not found", false)
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace) {
        len = estrlen(dialogbox->pending_buffer);
        current_msg = dialogbox->npc->messages[dialogbox->chunk_id];
        if (len < estrlen(current_msg)) {
            ememcpy(dialogbox->pending_buffer, current_msg,
                estrlen(current_msg) + 1);
            wrap_dialog_text(dialogbox);
        } else {
            dialogbox->chunk_id++;
            ememset(dialogbox->pending_buffer, 0,
                sizeof(dialogbox->pending_buffer));
            if (dialogbox->npc->messages[dialogbox->chunk_id] == NULL)
                dialogbox->is_visible = false;
        }
        return (true);
    }
    return (false);
}