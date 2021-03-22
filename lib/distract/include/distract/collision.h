/*
** EPITECH PROJECT, 2020
** collision
** File description:
** Source code
*/

#ifndef DISTRACT_COLLISION_H
#define DISTRACT_COLLISION_H
#include "SFML/Graphics.h"
#include "distract/game.h"
#include "distract/entity.h"

typedef struct ray {
    sfVector2f base;
    sfVector2f direction;
    float max_distance;
} ray_t;

typedef struct rayhit {
    sfVector2f point;
    entity_t *target;
} rayhit_t;

bool raycast_hit(game_t *game, ray_t *ray, rayhit_t *output_collided);

bool raycast_hit_all(game_t *game, ray_t *ray, entity_t **output_collided);

bool is_v2f_on_screen(game_t *game, sfVector2f vec);

bool is_v2i_on_screen(game_t *game, sfVector2i vec);

entity_t *get_entity_colliding_at(game_t *game, sfVector2f *point);

bool get_entities_colliding_at(game_t *game, sfVector2f *point,
    entity_t **output_collided, int *i);

#endif //DISTRACT_COLLISION_H