/*
** EPITECH PROJECT, 2021
** cine
** File description:
** ma
*/

#include "myrpg/cinema.h"
#include "distract/debug.h"

bool parse_move_camera(game_t *game UNUSED, struct cinema **head, char *buf)
{
    struct cinema tmp = {0};

    tmp.type = MOVE_CAMERA;
    tmp.u.move.x = rpg_strtoll(buf, &buf);
    tmp.u.move.y = rpg_strtoll(buf, &buf);
    tmp.cycle_count = rpg_strtoll(buf, &buf);
    return (push_back_cinema(head, &tmp));
}

bool parse_set_camera(game_t *game UNUSED, struct cinema **head, char *buf)
{
    struct cinema tmp = {0};

    tmp.type = SET_CAMERA;
    tmp.u.set.x = rpg_strtoll(buf, &buf);
    tmp.u.set.y = rpg_strtoll(buf, &buf);
    return (push_back_cinema(head, &tmp));
}

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
    if (ptr == NULL)
        return (false);
    tmp.u.disp.messages = esplit(ptr, '\n');
    tmp.u.disp.name = "";
    tmp.u.disp.boss_id = -1;
    tmp.u.disp.box = get_instance(game, DIALOGBOX);
    if (tmp.u.disp.box == NULL)
        return (false);
    free(ptr);
    tmp.cycle_count = rpg_strtoll(buf, &buf);
    return (tmp.u.disp.messages != NULL && push_back_cinema(head, &tmp));
}

bool parse_new_scene(game_t *game UNUSED, struct cinema **head, char *buf)
{
    struct cinema tmp = {0};
    char *ptr = estrchr(buf, '"') + 1;

    tmp.type = SWITCH_SCENE_CINEMATIC;
    parse_space(&buf);
    buf = estrchr(ptr, '"') + 1;
    if (ptr == NULL || ptr == (char *)1 ||
        buf == NULL || buf == (char *)1) {
        print_error("Missing quotes on string parse_new_scene");
        return (false);
    }
    tmp.u.scene = estrndup(ptr, buf - ptr - 1);
    if (tmp.u.scene == NULL)
        return (false);
    return (push_back_cinema(head, &tmp));
}