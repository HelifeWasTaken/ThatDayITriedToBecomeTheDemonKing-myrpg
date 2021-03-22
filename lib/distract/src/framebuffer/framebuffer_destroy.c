/*
** EPITECH PROJECT, 2020
** framebuffer_destroy
** File description:
** Source code
*/

#include "stdlib.h"
#include "SFML/Graphics.h"
#include "my/sfml.h"

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}