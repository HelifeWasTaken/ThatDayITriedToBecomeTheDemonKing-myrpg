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

    GBL_IS_IN_CINEMATIC = false;
    cinema = dcalloc(sizeof(cinema_t), 1);
    cinema->clock = create_pausable_clock(game);
    cinema->entity = entity;
    entity->instance = cinema;
    D_ASSERT(cinema, NULL, "Could not allocate cinema", false);
    D_ASSERT(cinema->clock, NULL, "Could not allocate clock", NULL);
    if (IS_GAME_FINISHED(game))
        return (create_cinema_end(game, cinema));
    // if (load_property_uint(get_game_state(game)->map.properties, &id,
    //    "cinematic_id", "") == false)
    //    return (true);
    if (GET_BIT(get_game_state(game)->save.cinematics, id) == true)
        return (true);
    return (create_cinema_load(game, cinema, id));
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

void update_cinema(game_t *game UNUSED, entity_t *entity)
{
    cinema_entity_t *cinema = entity->instance;
    void (*fun[CINEMATIC_TYPES_COUNT])(game_t *, cinema_t *cine) = {
        cinema_set, cinema_move, cinema_new_scene
    };

    if (cinema->cine == NULL) {
        GBL_IS_IN_CINEMATIC = false;
        destroy_entity(game, entity);
        return;
    }
    GBL_IS_IN_CINEMATIC = true;
    if (fun[cinema->cine->type] != NULL)
        fun[cinema->cine->type](game, cinema->cine);
    tick_pausable_clock(cinema->clock);
    if (cinema->clock->time >= 0.1f) {
        restart_pausable_clock(cinema->clock);
        if (update_cinema_data(&cinema->cine, game, entity) == false)
            return;
    }
}