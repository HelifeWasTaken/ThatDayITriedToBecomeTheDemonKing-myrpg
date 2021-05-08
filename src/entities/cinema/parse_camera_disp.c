/*
** EPITECH PROJECT, 2021
** cine
** File description:
** ma
*/

#include "myrpg/cinema.h"
#include "distract/debug.h"


static void read_disp_text(char s2[1000], char s[1000], char **ptr)
{
    unsigned int index_s = 0;
    char c;

    for (unsigned int i = 0; s2[i] &&  index_s < 999; i++) {
        c = s2[i];
        if (c == '\\' && s2[i + 1] == 'n') {
            i++;
            c = '\n';
        }
        s[index_s++] = c;
    }
    *ptr = estrdup(s);
}

static bool disp_set_box(game_t *game, struct cinema **head UNUSED,
        char *ptr, struct cinema *tmp)
{
    if (ptr == NULL)
        return (false);
    tmp->u.disp.dlg.messages = esplit(ptr, '\n');
    tmp->u.disp.dlg.name = "";
    tmp->u.disp.dlg.boss_id = -1;
    tmp->u.disp.dlg.box = get_instance(game, DIALOGBOX);
    if (tmp->u.disp.dlg.messages == NULL)
        return (false);
    if (tmp->u.disp.dlg.box == NULL)
        return (false);
    free(ptr);
    return (true);
}

bool parse_disp_text(game_t *game, struct cinema **head, char *buf)
{
    struct cinema tmp = {0};
    char *ptr = estrchr(buf, '"') + 1;
    char s[1000] = {0};
    char s2[1000] = {0};

    tmp.type = DISP_TEXT;
    parse_space(&buf);
    buf = estrchr(ptr, '"') + 1;
    if (ptr == NULL || ptr == (char *)1 || buf == NULL || buf == (char *)1) {
        print_error("Missing quotes on string parse_disp_text");
        return (false);
    }
    estrncpy(s2, ptr, buf - ptr - 1);
    read_disp_text(s2, s, &ptr);
    if (disp_set_box(game, head, ptr, &tmp) == false)
        return (false);
    tmp.cycle_count = rpg_strtoll(buf, &buf);
    return (tmp.u.disp.dlg.messages != NULL && push_back_cinema(head, &tmp));
}
