/*
** EPITECH PROJECT, 2020
** framebuffer
** File description:
** Source code
*/

#ifndef DISTRACT_FRAMEBUFFER_H
#define DISTRACT_FRAMEBUFFER_H
#include "SFML/Graphics.h"

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

framebuffer_t *framebuffer_create(int width, int height);
void framebuffer_clear(framebuffer_t *framebuffer);
void framebuffer_destroy(framebuffer_t *framebuffer);
void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
    sfColor color);

#endif //DISTRACT_FRAMEBUFFER_H