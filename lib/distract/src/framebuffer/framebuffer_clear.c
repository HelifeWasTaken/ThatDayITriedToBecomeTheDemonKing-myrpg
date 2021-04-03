/*
** EPITECH PROJECT, 2020
** framebuffer_clear
** File description:
** Source code
*/

#include "stdlib.h"
#include "SFML/Graphics.h"
#include "my/sfml.h"

void framebuffer_clear(framebuffer_t *framebuffer)
{
    int buffersize = 4 * framebuffer->width * framebuffer->height;
    int i = 0;

    while (i < buffersize) {
        framebuffer->pixels[i] = 255;
        i++;
    }
}