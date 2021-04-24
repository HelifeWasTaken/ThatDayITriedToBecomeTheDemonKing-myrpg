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
        if (wrapping_pos != 0 && wrapping_pos % 108 == 0) {
            wrapping_pos = wrap_current_word(dialog->pending_buffer, i);
        }
        wrapping_pos++;
    }
}

void hide_dialog(dialogbox_t *dialog)
{
    dialog->dialog = NULL;
    dialog->chunk_id = 0;
    dialog->is_visible = false;
}

void show_next_dialog(dialogbox_t *dialogbox)
{
    dialogbox->chunk_id++;
    ememset(dialogbox->pending_buffer, 0, sizeof(dialogbox->pending_buffer));
    if (dialogbox->dialog->messages[dialogbox->chunk_id] == NULL)
        hide_dialog(dialogbox);
}

bool show_dialog(dialog_t *dialog)
{
    dialogbox_t *dialogbox = dialog->box;
    size_t buffer_len = (sizeof(dialogbox->pending_buffer) / sizeof(char)) - 1;

    for (int i = 0; dialog->messages[i] != NULL; i++)
        if (estrlen(dialog->messages[i]) > buffer_len)
            return (false);
    ememset(dialogbox->pending_buffer, 0, sizeof(dialogbox->pending_buffer));
    dialogbox->dialog = dialog;
    dialogbox->chunk_id = 0;
    dialogbox->is_visible = true;
    return (true);
}