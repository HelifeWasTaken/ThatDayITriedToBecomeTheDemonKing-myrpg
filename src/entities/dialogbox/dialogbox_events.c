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

static void trigger_dialog_space(game_t *game, dialogbox_t *dialogbox)
{
    char *current_msg;
    size_t len;

    len = estrlen(dialogbox->pending_buffer);
    current_msg = dialogbox->dialog->messages[dialogbox->chunk_id];
    if (len < estrlen(current_msg)) {
        ememcpy(dialogbox->pending_buffer, current_msg,
            estrlen(current_msg) + 1);
        wrap_dialog_text(dialogbox);
    } else {
        show_next_dialog(game, dialogbox);
    }
}

bool handle_dialogbox_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    dialogbox_t *dialogbox = entity->instance;

    if (!dialogbox->is_visible)
        return (false);
    D_ASSERT(dialogbox->dialog, NULL, "dialog linked to box not found", false)
    if (event->type == sfEvtKeyPressed && (event->key.code == sfKeySpace
        || event->key.code == sfKeyEnter)) {
        trigger_dialog_space(game, dialogbox);
        return (true);
    }
    return (false);
}
