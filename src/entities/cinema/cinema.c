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

static bool set_cinema(game_t *game, cinema_entity_t *cinema)
{
    u64_t id = 0;

    if (IS_GAME_FINISHED(game))
        return (create_cinema_end(game, cinema));
    if (load_property_uint(get_game_state(game)->map.properties, &id,
        "cinematic_id", "") == false)
        return (true);
    if (GET_BIT(get_game_state(game)->save.cinematics, id) == true)
        return (true);
    return (create_cinema_load(game, cinema, id));
}

bool create_cinema(game_t *game UNUSED, entity_t *entity)
{
    cinema_entity_t *cinema = NULL;

    GBL_IS_IN_CINEMATIC = false;
    cinema = dcalloc(sizeof(cinema_t), 1);
    D_ASSERT(cinema, NULL, "Could not allocate cinema", false);
    cinema->clock = create_pausable_clock(game);
    cinema->entity = entity;
    entity->instance = cinema;
    cinema->box = get_instance(game, DIALOGBOX);
    cinema->hero = get_instance(game, HERO);
    D_ASSERT(cinema->clock, NULL, "Could not allocate clock", NULL);
    D_ASSERT(cinema->box, NULL, "Could not get dialog box", NULL);
    D_ASSERT(cinema->hero, NULL, "Could not get hero", NULL);
    cinema->entity->z = -1;
    return (set_cinema(game, cinema));
}

void destroy_cinema(game_t *game UNUSED, entity_t *entity)
{
    cinema_entity_t *cinema = entity->instance;

    while (cinema->cine)
        pop_front_cinema(game, &cinema->cine);
    destroy_pausable_clock(cinema->clock);
    free(cinema);
}

bool update_cinema_data(cinema_entity_t **cinema,
        game_t *game, entity_t *entity)
{
    (*cinema)->cine->cycle_count--;
    if ((*cinema)->cine->cycle_count < 0)
        pop_front_cinema(game, &(*cinema)->cine);
    if ((*cinema)->cine == NULL) {
        GBL_IS_IN_CINEMATIC = false;
        destroy_entity(game, entity);
        if (IS_GAME_FINISHED(game))
            stop_end_scene(game, *cinema);
        return (false);
    }
    return (true);
}

void update_cinema(game_t *game UNUSED, entity_t *entity)
{
    cinema_entity_t *cinema = entity->instance;
    void (*fun[CINEMATIC_TYPES_COUNT])(game_t *, cinema_entity_t *cine) = {
        cinema_set, cinema_move, cinema_new_scene,
        cinema_hero_set, cinema_disp_text
    };

    if (cinema->cine == NULL) {
        GBL_IS_IN_CINEMATIC = false;
        destroy_entity(game, entity);
        return;
    }
    GBL_IS_IN_CINEMATIC = true;
    if (fun[cinema->cine->type] != NULL)
        fun[cinema->cine->type](game, cinema);
    tick_pausable_clock(cinema->clock);
    if (cinema->clock->time >= 0.1f) {
        restart_pausable_clock(cinema->clock);
        if (update_cinema_data(&cinema, game, entity) == false)
            return;
    }
}
