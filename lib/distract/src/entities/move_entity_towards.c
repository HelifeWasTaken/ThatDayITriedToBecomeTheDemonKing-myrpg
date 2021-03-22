/*
** EPITECH PROJECT, 2020
** entity
** File description:
** Entity
*/
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/math.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"

sfVector2f move_entity_towards(entity_t *entity, sfVector2f target,
    float distance)
{
    sfVector2f movement = v2fnormalized(v2fsub(&target, &entity->pos));

    v2fadd(&entity->pos, v2fmulf(&movement, distance));
    return movement;
}