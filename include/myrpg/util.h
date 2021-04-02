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
        sfRectangleShape_setSize(rc, VEC2F(16, 16));
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

#define PRINT_V2F(v) \
    printf("<x: %f, y: %f>\n", v.x, v.y)

#define PRINT_V2I(v) \
    printf("<x: %d, y: %d>\n", (int)v.x, (int)v.y)

#define PRINT_RF(r)                                        \
    printf("<top: %f, left: %f, width: %f, height: %f>\n", \
           r.top, r.left, r.width, r.height)

#define PRINT_RI(r)                                        \
    printf("<top: %d, left: %d, width: %d, height: %d>\n", \
           (int)r.top, (int)r.left, (int)r.width, (int)r.height)

#define PERCENT(value, percent) \
    ((value / 100) * percent)

#endif