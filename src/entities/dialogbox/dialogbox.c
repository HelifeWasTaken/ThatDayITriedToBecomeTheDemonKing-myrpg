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
#include <stdio.h>


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
    char *tmp = NULL;
    size_t len = 0;

    if (!dialogbox->is_visible)
        return;
    D_ASSERT(dialogbox->dialog, NULL, "npc linked to dialog not found", (void)0)
    tick_pausable_clock(dialogbox->clock);
    tmp = dialogbox->dialog->messages[dialogbox->chunk_id];
    if (dialogbox->clock->time > 0.5) {
        D_ASSERT(tmp, NULL, "Invalid state, unexpected null", (void)0);
        len = estrlen(dialogbox->pending_buffer);
        if (len < estrlen(tmp)) {
            dialogbox->pending_buffer[len] = tmp[len];
            dialogbox->pending_buffer[len + 1] = '\0';
            wrap_dialog_text(dialogbox);
        }
    }
    sfText_setString(dialogbox->name_text, dialogbox->dialog->name);
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
    D_ASSERT(dialogbox->dialog, NULL, "dialog linked to box not found", false)
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace) {
        len = estrlen(dialogbox->pending_buffer);
        current_msg = dialogbox->dialog->messages[dialogbox->chunk_id];
        if (len < estrlen(current_msg)) {
            ememcpy(dialogbox->pending_buffer, current_msg,
                estrlen(current_msg) + 1);
            wrap_dialog_text(dialogbox);
        } else {
            show_next_dialog(dialogbox);
        }
        return (true);
    }
    return (false);
}