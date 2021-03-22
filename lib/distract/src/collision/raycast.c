/*
** EPITECH PROJECT, 2020
** raycast
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

bool raycast_hit_all(game_t *game, ray_t *ray, entity_t **collided)
{
    sfVector2f position = ray->base;
    sfVector2f last_position;
    sfVector2f tmp;
    int i = 0;

    collided[0] = NULL;
    ray->direction = v2fnormalized(&ray->direction);
    if (v2fmagnitude(&ray->direction) == 0)
        return (false);
    while (v2fdistance(&ray->base, &position) < ray->max_distance) {
        last_position = position;
        v2fadd(&position, &ray->direction);
        if (!is_v2f_on_screen(game, position))
            break;
        for (float g = 0; g < 1; g += 0.1) {
            tmp = v2flerp(&last_position, &position, g);
            get_entities_colliding_at(game, &tmp, collided, &i);
        }
    }
    return (*collided != NULL);
}

static bool check_raycast_hit(game_t *game, sfVector2f *v, rayhit_t *collided)
{
    entity_t *target = get_entity_colliding_at(game, v);

    if (target == NULL)
        return (false);
    collided->target = target;
    collided->point = *v;
    return (true);
}

bool raycast_hit(game_t *game, ray_t *ray, rayhit_t *collided)
{
    sfVector2f position = ray->base;
    sfVector2f last_position;
    sfVector2f tmp;
    sfVector2f direction = v2fnormalized(&ray->direction);

    if (v2fmagnitude(&direction) == 0)
        return (false);
    while (v2fdistance(&ray->base, &position) < ray->max_distance) {
        last_position = position;
        v2fadd(&position, &direction);
        if (!is_v2f_on_screen(game, position))
            return (false);
        for (float f = 0; f < 1; f += 0.5) {
            tmp = v2flerp(&last_position, &position, f);
            if (check_raycast_hit(game, &tmp, collided))
                return (true);
        }
    }
    return (false);
}