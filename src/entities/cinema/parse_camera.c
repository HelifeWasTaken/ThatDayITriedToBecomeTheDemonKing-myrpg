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
