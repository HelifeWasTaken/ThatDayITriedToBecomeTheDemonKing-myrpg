/*
** EPITECH PROJECT, 2020
** point
** File description:
** Source code
*/
#include "stdlib.h"
#include "stdio.h"
#include "SFML/Graphics.h"
#include "distract/math.h"
#include "distract/collision.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/graphics.h"

static bool is_in_output_list(entity_t **output_collided, int size, entity_t *e)
{
    for (int j = 0; j < size; j++) {
        if (e == output_collided[j])
            return (true);
    }
    return (false);
}

entity_t *get_entity_colliding_at(game_t *game, sfVector2f *point)
{
    for (entity_t *e = game->scene->entities; e != NULL; e = e->next) {
        if (e->do_collide_point == NULL)
            continue;
        if (e->do_collide_point(e, point)) {
            return (e);
        }
    }
    return (NULL);
}

bool get_entities_colliding_at(game_t *game, sfVector2f *point,
    entity_t **output_collided, int *append_pos)
{
    for (entity_t *e = game->scene->entities; e != NULL; e = e->next) {
        if (e->do_collide_point == NULL)
            continue;
        if (e->do_collide_point(e, point)) {
            if (!is_in_output_list(output_collided, *append_pos, e)) {
                output_collided[*append_pos] = e;
                (*append_pos)++;
            }
        }
    }
    output_collided[*append_pos] = NULL;
    return (*output_collided != NULL);
}