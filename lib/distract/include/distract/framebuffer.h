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

///
/// Create a framebuffer, a drawable area of pixels.
///
framebuffer_t *framebuffer_create(int width, int height);

///
/// Clear the framebuffer
///
void framebuffer_clear(framebuffer_t *framebuffer);

///
/// Destroy the framebuffer.
///
void framebuffer_destroy(framebuffer_t *framebuffer);

///
/// Put a pixel in the framebuffer.
///
void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
    sfColor color);

#endif //DISTRACT_FRAMEBUFFER_H