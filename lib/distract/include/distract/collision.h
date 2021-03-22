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

///
/// Details about the raycast
///
typedef struct ray {
    ///
    /// Origin of the ray
    ///
    sfVector2f base;

    ///
    /// Direction to send the ray towards
    ///
    sfVector2f direction;

    ///
    /// Max distance of the base
    ///
    float max_distance;
} ray_t;

///
/// Element hit by the raycast
///
typedef struct rayhit {
    sfVector2f point;
    entity_t *target;
} rayhit_t;

///
/// Cast a ray and hit the nearest element.
/// Will fill the structure at output_collided with the data.
///
bool raycast_hit(game_t *game, ray_t *ray, rayhit_t *output_collided);

///
/// Cast a ray and hit as many elements as possible.
///
bool raycast_hit_all(game_t *game, ray_t *ray, entity_t **output_collided);

///
/// Check if the position is inside the bounds of the screen
///
bool is_v2f_on_screen(game_t *game, sfVector2f vec);

///
/// Check if the position is inside the bounds of the screen
///
bool is_v2i_on_screen(game_t *game, sfVector2i vec);

///
/// Get the first entity that can collide the point.
///
entity_t *get_entity_colliding_at(game_t *game, sfVector2f *point);

///
/// Get all the entities that can collide the point.
///
/// Will get the value pointed by of append_pos as start index and set the
/// value pointed to the new appendable position, in sort that after the
/// function call, `output_collided[*append_pos] = NULL`.
///
bool get_entities_colliding_at(game_t *game, sfVector2f *point,
    entity_t **output_collided, int *append_pos);

#endif //DISTRACT_COLLISION_H