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

void cinema_new_music(game_t *game, cinema_entity_t *cine)
{
    if (get_game_state(game)->end_music != NULL) {
        sfMusic_stop(get_game_state(game)->end_music);
        sfMusic_destroy(get_game_state(game)->end_music);
    }
    get_game_state(game)->end_music =
        sfMusic_createFromFile(cine->cine->u.music);
    if (get_game_state(game)->end_music != NULL)
        sfMusic_play(get_game_state(game)->end_music);
}

void cinema_end_music(game_t *game UNUSED, cinema_entity_t *cine UNUSED)
{
    if (get_game_state(game)->end_music != NULL) {
        sfMusic_stop(get_game_state(game)->end_music);
        sfMusic_destroy(get_game_state(game)->end_music);
        get_game_state(game)->end_music = NULL;
    }
}
