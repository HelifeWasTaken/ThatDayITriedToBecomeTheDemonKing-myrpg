/*
** EPITECH PROJECT, 2020
** my_put_pixel
** File description:
** Source code
*/

#include "stdlib.h"
#include "SFML/Graphics.h"
#include "my/sfml.h"

void put_pixel(framebuffer_t *framebuffer, unsigned int x,
    unsigned int y, sfColor color)
{
    if (x < 0 || y < 0 || x > framebuffer->width || y > framebuffer->height)
        return;
    framebuffer->pixels[4 * (y * framebuffer->width + x)] = color.r;
    framebuffer->pixels[4 * (y * framebuffer->width + x) + 1] = color.g;
    framebuffer->pixels[4 * (y * framebuffer->width + x) + 2] = color.b;
    framebuffer->pixels[4 * (y * framebuffer->width + x) + 3] = color.a;
}