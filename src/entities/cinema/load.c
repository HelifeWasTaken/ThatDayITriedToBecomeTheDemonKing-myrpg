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

static const char *CINEMA_FILES[CINEMATIC_COUNT] = {
    "asset/cinematic/village.cinematic",
    "asset/cinematic/map_monde.cinematic",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

bool create_cinema_load(game_t *game, cinema_entity_t *cinema, u64_t id)
{
    get_game_state(game)->save.cinematics = SET_BIT(
        get_game_state(game)->save.cinematics, true, id);
    if (CINEMA_FILES[id] == NULL) {
        print_error("No cinematic here");
        return (true);
    }
    if (cinema_reader_command(game, &cinema->cine, CINEMA_FILES[id]) == false) {
        print_error("Error trying to load cinema reader");
        return (false);
    }
    return (true);
}

bool force_cinematic(game_t *game UNUSED, u64_t id)
{
    cinema_entity_t *cinema = NULL;
    entity_t *entity = dcalloc(sizeof(entity_t), 1);
    entity_info_t *info = get_entity_info(game, CINEMA);

    GBL_IS_IN_CINEMATIC = false;
    D_ASSERT(entity && info, false,
        "Entity is not registered or allocation error", false);
    cinema = dcalloc(sizeof(cinema_t), 1);
    cinema->clock = create_pausable_clock(game);
    cinema->entity = entity;
    entity->instance = cinema;
    D_ASSERT(cinema, NULL, "Could not allocate cinema", false);
    D_ASSERT(cinema->clock, NULL, "Could not allocate clock", NULL);
    if (GET_BIT(get_game_state(game)->save.cinematics, id) == true)
        return (true);
    if (create_cinema_load(game, cinema, id) == true) {
        add_to_entities(game, entity);
        return (true);
    }
    return (false);
}
