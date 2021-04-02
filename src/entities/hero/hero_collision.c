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

static const int HERO_MOVE_SPEED = 5;

void player_move_up(hero_t *hero, sfIntRect *rect)
{
    sfVector2u mapsize = hero->collision->map.map_size;
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_v[] = {
        GET_REAL_POSITION_XY(entitypos, rect->width / 2,
            rect->height / 3)
    };

    for (usize_t i = 0; i < ARRAY_SIZE(pos_v); i++) {
        if (pos_v[i].x >= hero->collision->map.map_size.x ||
            pos_v[i].y >= hero->collision->map.map_size.y) {
            print_error("Warning: Unexpected collision encoutered");
            return;
        }
        if (GET_POS_MAP(pos_v[i], mapsize.x,
            hero->collision->map.v_collision.layer) == true)
            return;
    }
    hero->entity->pos.y += -HERO_MOVE_SPEED;
}

void player_move_down(hero_t *hero, sfIntRect *rect)
{
    sfVector2u mapsize = hero->collision->map.map_size;
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_v[] = {
        GET_REAL_POSITION_XY(entitypos, rect->width / 2, rect->height / 2)
    };

    for (usize_t i = 0; i < ARRAY_SIZE(pos_v); i++) {
        if (pos_v[i].x >= hero->collision->map.map_size.x ||
            pos_v[i].y >= hero->collision->map.map_size.y) {
            print_error("Warning: Unexpected collision encoutered");
            return;
        }
        if (GET_POS_MAP(pos_v[i], mapsize.x,
            hero->collision->map.v_collision.layer) == true)
            return;
    }
    hero->entity->pos.y += HERO_MOVE_SPEED;
}

void player_move_left(hero_t *hero, sfIntRect *rect)
{
    sfVector2u mapsize = hero->collision->map.map_size;
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_v[] = { GET_REAL_POSITION_XY(
        entitypos, 0, (rect->height / 2) - 2) };

    for (usize_t i = 0; i < ARRAY_SIZE(pos_v); i++) {
        if (pos_v[i].x >= hero->collision->map.map_size.x ||
            pos_v[i].y >= hero->collision->map.map_size.y) {
            print_error("Warning: Unexpected collision encoutered");
            return;
        }
        if (GET_POS_MAP(pos_v[i], mapsize.x,
            hero->collision->map.v_collision.layer) == true)
            return;
    }
    hero->entity->pos.x -= HERO_MOVE_SPEED;
}

void player_move_right(hero_t *hero, sfIntRect *rect)
{
    sfVector2u mapsize = hero->collision->map.map_size;
    sfVector2f entitypos = hero->entity->pos;
    sfVector2u pos_v[] = {
        GET_REAL_POSITION_XY(
            entitypos, (rect->width / 2) + 4, (rect->height / 2) - 2)
    };

    for (usize_t i = 0; i < ARRAY_SIZE(pos_v); i++) {
        if (pos_v[i].x >= hero->collision->map.map_size.x ||
            pos_v[i].y >= hero->collision->map.map_size.y) {
            print_error("Warning: Unexpected collision encoutered");
            return;
        }
        if (GET_POS_MAP(pos_v[i], mapsize.x,
            hero->collision->map.v_collision.layer) == true)
            return;
    }
    hero->entity->pos.x += HERO_MOVE_SPEED;
}