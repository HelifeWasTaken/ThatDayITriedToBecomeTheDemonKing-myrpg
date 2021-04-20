/*
** EPITECH PROJECT, 2021
** util
** File description:
** til
*/

#ifndef __UTIL__H__
#define __UTIL__H__

#include <SFML/Graphics.h>
#include "distract/graphics.h"
#include "distract/def.h"
#include "myrpg/matrix.h"
#include "erty/eprintf.h"
#include "myrpg/state.h"

#define SIZE_COLLIDE_R 4

typedef struct {
    sfVector2f topleft;
    sfVector2f topright;
    sfVector2f bottomleft;
    sfVector2f bottomright;
} corner_t;

enum corner_type {
    CORNER_SPRITE,
    CORNER_RECT
};

// Returns each corner of instance in the world
// If r is a rect it should be passed as a pointer
static inline corner_t get_corners(void *r, enum corner_type type)
{
    sfFloatRect rect = {0};

    if (type == CORNER_SPRITE)
        rect = sfSprite_getGlobalBounds((const sfSprite *)r);
    else
        rect = *(sfFloatRect *)r;
    return ((corner_t){
        .topleft = VEC2F(rect.left, rect.top),
        .topright = VEC2F(rect.left + rect.width, rect.top),
        .bottomleft = VEC2F(rect.left, rect.top + rect.height),
        .bottomright = VEC2F(rect.left + rect.width, rect.top + rect.height)
    });
}

static inline void draw_rectangle_shape_global_bound(sfRenderWindow *window,
                                                    sfSprite *sprite, bool full)
{
    sfRectangleShape *rc = sfRectangleShape_create();
    corner_t c = get_corners(sprite, CORNER_SPRITE);

    sfRectangleShape_setFillColor(rc, sfRed);
    if (full)
        sfRectangleShape_setSize(rc,
            VEC2F(c.topright.x - c.topleft.x, c.bottomleft.y  - c.topleft.y));
    else {
        sfRectangleShape_setSize(rc, VEC2F(SIZE_COLLIDE_R, SIZE_COLLIDE_R));
        sfRectangleShape_setPosition(rc, c.topright);
        sfRenderWindow_drawRectangleShape(window, rc, NULL);
        sfRectangleShape_setPosition(rc, c.bottomright);
        sfRenderWindow_drawRectangleShape(window, rc, NULL);
        sfRectangleShape_setPosition(rc, c.bottomleft);
        sfRenderWindow_drawRectangleShape(window, rc, NULL);
        sfRenderWindow_drawRectangleShape(window, rc, NULL);
    }
    sfRectangleShape_setPosition(rc, c.topleft);
    sfRenderWindow_drawRectangleShape(window, rc, NULL);
    sfRectangleShape_destroy(rc);
}

static inline void draw_rectangle_at_point(sfRenderWindow *window,
        sfVector2f *pos)
{
    sfRectangleShape *rc = sfRectangleShape_create();

    sfRectangleShape_setSize(rc, VEC2F(SIZE_COLLIDE_R, SIZE_COLLIDE_R));
    sfRectangleShape_setPosition(rc, *pos);
    sfRectangleShape_setFillColor(rc, sfRed);
    sfRenderWindow_drawRectangleShape(window, rc, NULL);
    sfRectangleShape_destroy(rc);
}

bool deser_vector2i(struct json *conf, size_t offset, void *data);
bool deser_irect(struct json *conf, size_t offset, void *data);
bool deser_vector2f(struct json *conf, size_t offset, void *data);
bool deser_frect(struct json *conf, size_t offset, void *data);

#define PRINT_V2F(v) \
    eprintf("<x: %d, y: %d>\n", (int)v.x, (int)v.y)

#define PRINT_V2I(v) \
    eprintf("<x: %d, y: %d>\n", (int)v.x, (int)v.y)

#define PRINT_RF(r)                                        \
    eprintf("<top: %d, left: %d, width: %d, height: %d>\n", \
        (int)r.top, (int)r.left, (int)r.width, (int)r.height)

#define PRINT_RI(r)                                        \
    eprintf("<top: %d, left: %d, width: %d, height: %d>\n", \
        (int)r.top, (int)r.left, (int)r.width, (int)r.height)

#define CAST_V2(cast, v) \
    (cast){v.x, v.y}

#define CAST_R(cast, r) \
    (cast){ .top = r.top, .left = r.left, .width = r.width, .height = r.height }

game_state_t *get_game_state(game_t *game);

#endif