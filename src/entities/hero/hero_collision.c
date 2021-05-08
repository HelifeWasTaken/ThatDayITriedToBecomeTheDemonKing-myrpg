/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** hero_collision.c
*/

#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "stdio.h"
#include "myrpg/define.h"
#include "distract/debug.h"
#include "myrpg/util.h"

static bool check_collision(sfVector2u *pos_v, hero_t *hero)
{
    if (hero->disable_collision == true)
        return (true);
    if (pos_v->x >= hero->layers->manager.mapsize.x ||
            pos_v->y >= hero->layers->manager.mapsize.y) {
        return (false);
    }
    return (!hero->layers->manager.collision->data.map[
        pos_v->x + pos_v->y * hero->layers->manager.mapsize.x]);
}

void player_move_up(hero_t *hero, sfIntRect *rect)
{
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_v =  GET_REAL_POSITION_XY(entitypos, rect->width / 2,
            rect->height / 3, hero->layers->manager.tilesize);

    if (check_collision(&pos_v, hero))
        hero->entity->pos.y += -hero->speed;
}

void player_move_down(hero_t *hero, sfIntRect *rect)
{
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_v = GET_REAL_POSITION_XY(entitypos,
        rect->width / 2, rect->height / 2,
        hero->layers->manager.tilesize);

    if (check_collision(&pos_v, hero))
        hero->entity->pos.y += hero->speed;
}

void player_move_left(hero_t *hero, sfIntRect *rect)
{
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_v = GET_REAL_POSITION_XY(
        entitypos, 0, (rect->height / 2) - 2,
        hero->layers->manager.tilesize);

    if (check_collision(&pos_v, hero))
        hero->entity->pos.x -= hero->speed;
}

void player_move_right(hero_t *hero, sfIntRect *rect)
{
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_v = GET_REAL_POSITION_XY(
        entitypos, (rect->width / 2) + 4, (rect->height / 2) - 2,
        hero->layers->manager.tilesize);

    if (check_collision(&pos_v, hero))
        hero->entity->pos.x += hero->speed;
}
