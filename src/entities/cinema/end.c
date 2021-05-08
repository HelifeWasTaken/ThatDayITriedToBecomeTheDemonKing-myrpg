/*
** EPITECH PROJECT, 2020
** cinema
** File description:
** Entity
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include "myrpg/cinema.h"
#include "myrpg/scenes.h"

static const char *CINEMA_FILES_END[] = {
    "asset/cinematic/end/1.cinematic",
    "asset/cinematic/end/2.cinematic",
    "asset/cinematic/end/3.cinematic"
};

static const char *MUSIC_END = "asset/song/travel_cut.ogg";

bool stop_end_scene(game_t *game, cinema_entity_t *cinema UNUSED)
{
    parameters_t params = {0};

    ememcpy(&params, &get_game_state(game)->params, sizeof(params));
    if (get_game_state(game)->end_music) {
        sfMusic_stop(get_game_state(game)->end_music);
        sfMusic_destroy(get_game_state(game)->end_music);
        get_game_state(game)->end_music = NULL;
    }
    ememset(game->state, 0, sizeof(game_state_t));
    ememcpy(&get_game_state(game)->params, &params, sizeof(params));
    game->scene->world_file = DEFAULT_WORLD_FILE;
    get_game_state(game)->save.player_pos = DEFAULT_PLAYER_POS;
    switch_to_scene(game, MENU_SCENE);
    return (true);
}

static bool play_end_music(game_t *game, cinema_entity_t *cinema UNUSED)
{
    if (get_game_state(game)->end_music == NULL) {
        get_game_state(game)->end_music = sfMusic_createFromFile(MUSIC_END);
        if (get_game_state(game)->end_music == NULL)
            return (false);
    }
    if (sfMusic_getStatus(get_game_state(game)->end_music) != sfPlaying)
        sfMusic_play(get_game_state(game)->end_music);
    return (true);
}

static bool read_end(game_t *game, cinema_entity_t *cinema)
{
    if (cinema_reader_command(game, &cinema->cine,
        CINEMA_FILES_END[
            get_game_state(game)->save.cinematics_end_count++]) == false) {
        print_error("Error trying to load cinema reader");
        return (false);
    }
    return (true);
}

bool create_cinema_end(game_t *game, cinema_entity_t *cinema)
{
    if (play_end_music(game, cinema) == false)
        return (false);
    if (ARRAY_SIZE(CINEMA_FILES_END) <=
            get_game_state(game)->save.cinematics_end_count)
        return (stop_end_scene(game, cinema));
    return (read_end(game, cinema));
}
