/*
** EPITECH PROJECT, 2020
** framebuffer_create
** File description:
** Source code
*/

#include "stdlib.h"
#include "SFML/Graphics.h"
#include "my/sfml.h"

framebuffer_t *framebuffer_create(int width, int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    int buffersize = 4 * width * height;
    sfUint8 *pixels = malloc(sizeof(sfUint8) * buffersize);

    if (framebuffer == NULL || pixels == NULL)
        return (NULL);
    framebuffer->pixels = pixels;
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer_clear(framebuffer);
    return (framebuffer);
}