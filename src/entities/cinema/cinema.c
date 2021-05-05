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

bool GBL_IS_IN_CINEMATIC = false;

bool create_cinema(game_t *game UNUSED, entity_t *entity)
{
    cinema_entity_t *cinema = NULL;
    u64_t id = 0;
    const char *cinema_files[] = {"asset/map_asset/village.cinematic",
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    GBL_IS_IN_CINEMATIC = false;
    //if (load_property_uint(get_game_state(game)->map.properties, &id,
    //    "cinematic_id", "") == false)
    //    return (true);
    cinema = dcalloc(sizeof(cinema_t), 1);
    cinema->clock = create_pausable_clock(game);
    cinema->entity = entity;
    entity->instance = cinema;
    D_ASSERT(cinema, NULL, "Could not allocate cinema", false);
    if (GET_BIT(get_game_state(game)->save.cinematics, id) == true)
        return (true);
    get_game_state(game)->save.cinematics = SET_BIT(
        get_game_state(game)->save.cinematics, true, id);
    fflush(stdout);
    if (cinema_files[id] == NULL) {
        print_error("No cinematic here");
        return (true);
    }
    if (cinema_reader_command(&cinema->cine, cinema_files[id]) == false) {
        print_error("Error trying to load cinema reader");
        return (false);
    }
    return (true);
}

void destroy_cinema(game_t *game UNUSED, entity_t *entity)
{
    cinema_entity_t *cinema = entity->instance;

    while (cinema->cine)
        pop_front_cinema(&cinema->cine);
    destroy_pausable_clock(cinema->clock);
    free(cinema);
}

bool update_cinema_data(cinema_t **cine, game_t *game, entity_t *entity)
{
    (*cine)->cycle_count--;
    if ((*cine)->cycle_count < 0)
        pop_front_cinema(cine);
    if (*cine == NULL) {
        GBL_IS_IN_CINEMATIC = false;
        destroy_entity(game, entity);
        return (false);
    }
    return (true);
}

void cinema_set(game_t *game, cinema_t *cine)
{
    sfView_setCenter(game->view,
        (sfVector2f){ cine->u.set.x, cine->u.set.y });
    set_game_view(game, game->view);
}

void cinema_move(game_t *game, cinema_t *cine)
{
    sfVector2f move = VEC2F(cine->u.move.x, cine->u.move.y);

    move.x /= 100;
    move.y /= 100;
    sfView_move(game->view, move);
    set_game_view(game, game->view);
}

void update_cinema(game_t *game UNUSED, entity_t *entity)
{
    cinema_entity_t *cinema = entity->instance;

    if (cinema->cine == NULL) {
        GBL_IS_IN_CINEMATIC = false;
        destroy_entity(game, entity);
        return;
    }
    GBL_IS_IN_CINEMATIC = true;
    if (cinema->cine->type == SET_CAMERA)
        cinema_set(game, cinema->cine);
    else if (cinema->cine->type == MOVE_CAMERA)
        cinema_move(game, cinema->cine);
    tick_pausable_clock(cinema->clock);
    if (cinema->clock->time >= 0.1f) {
        restart_pausable_clock(cinema->clock);
        if (update_cinema_data(&cinema->cine, game, entity) == false)
            return;
    }
}