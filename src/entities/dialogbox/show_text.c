/*
** EPITECH PROJECT, 2021
** show_text
** File description:
** Source code
*/

#include "distract/util.h"
#include "myrpg/entities.h"
#include <SFML/Graphics/Text.h>

static int wrap_current_word(char *buffer, int index)
{
    int i = index;
    int shift = 0;

    for (; i >= 0; i--) {
        if (buffer[i] == ' ' || buffer[i] == '\n') {
            buffer[i] = '\n';
            break;
        }
        shift++;
    }
    return (shift);
}

void wrap_dialog_text(dialogbox_t *dialog)
{
    int i = 0;
    int wrapping_pos = 0;

    for (; dialog->pending_buffer[i] != '\0'; i++) {
        if (wrapping_pos != 0 && wrapping_pos % 100 == 0) {
            wrapping_pos = wrap_current_word(dialog->pending_buffer, i);
        }
        wrapping_pos++;
    }
}

void show_dialog(npc_t *npc)
{
    dialogbox_t *dialog = npc->dialog;

    dialog->npc = npc;
    dialog->chunk_id = 0;
    dialog->is_visible = true;
}