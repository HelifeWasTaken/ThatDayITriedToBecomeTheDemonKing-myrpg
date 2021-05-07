/*
** EPITECH PROJECT, 2021
** cine
** File description:
** ma
*/

#include "myrpg/cinema.h"
#include "distract/debug.h"

bool parse_hero_pos(game_t *game UNUSED, struct cinema **head, char *buf)
{
    struct cinema tmp = {0};

    tmp.type = SET_HERO;
    tmp.u.set.x = rpg_strtoll(buf, &buf);
    tmp.u.set.y = rpg_strtoll(buf, &buf);
    return (push_back_cinema(head, &tmp));
}