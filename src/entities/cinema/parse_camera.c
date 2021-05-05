/*
** EPITECH PROJECT, 2021
** cine
** File description:
** ma
*/

#include "myrpg/cinema.h"

bool parse_move_camera(struct cinema **head, char *buf)
{
    struct cinema tmp = {0};

    tmp.type = MOVE_CAMERA;
    tmp.u.move.x = rpg_strtoll(buf, &buf);
    tmp.u.move.y = rpg_strtoll(buf, &buf);
    tmp.cycle_count = rpg_strtoll(buf, &buf);
    return (push_back_cinema(head, &tmp));
}

bool parse_set_camera(struct cinema **head, char *buf)
{
    struct cinema tmp = {0};

    tmp.type = SET_CAMERA;
    tmp.u.set.x = rpg_strtoll(buf, &buf);
    tmp.u.set.y = rpg_strtoll(buf, &buf);
    return (push_back_cinema(head, &tmp));
}

static void read_disp_text(struct cinema *tmp, char s[1000])
{
    unsigned int index_s = 0;
    char c;

    for (unsigned int i = 0; tmp->u.disp[i] &&  index_s < 999; i++) {
        c = tmp->u.disp[i];
        if (c == '\\' && tmp->u.disp[i + 1] == 'n') {
            i++;
            c = '\n';
        }
        s[index_s++] = c;
    }
}

bool parse_disp_text(struct cinema **head, char *buf)
{
    struct cinema tmp = {0};
    char *ptr = NULL;
    char s[1000] = {0};

    tmp.type = DISP_TEXT;
    parse_space(&buf);
    ptr = estrchr(buf, '"') + 1;
    buf = estrchr(ptr, buf - ptr) + 1;
    tmp.u.disp = estrndup(ptr, buf - ptr - 1);
    if (tmp.u.disp == NULL)
        return (false);
    read_disp_text(&tmp, s);
    free(tmp.u.disp);
    tmp.u.disp = estrdup(s);
    tmp.cycle_count = rpg_strtoll(buf, &buf);
    return (push_back_cinema(head, &tmp));
}
