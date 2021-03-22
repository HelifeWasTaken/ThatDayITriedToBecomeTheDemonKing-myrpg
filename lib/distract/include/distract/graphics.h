/*
** EPITECH PROJECT, 2020
** graphics
** File description:
** Source code
*/

#ifndef DISTRACT_GRAPHICS_H
#define DISTRACT_GRAPHICS_H
#include "SFML/Graphics.h"

sfText *align_text_bottom(sfText *text, int y_pos);
sfText *align_text_right(sfText *text, int x_pos);
sfText *center_text_x(sfText *text, int start_x, int end_x);
sfText *center_text_y(sfText *text, int start_y, int end_y);
sfSprite *create_sprite(sfTexture *texture, sfIntRect *rect);

#endif //DISTRACT_GRAPHICS_H