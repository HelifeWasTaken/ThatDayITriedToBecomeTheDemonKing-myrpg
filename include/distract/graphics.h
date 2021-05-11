/*
** EPITECH PROJECT, 2020
** graphics
** File description:
** Source code
*/

#ifndef DISTRACT_GRAPHICS_H
#define DISTRACT_GRAPHICS_H
#include "SFML/Graphics.h"

///
/// Align the bottom of the sfText to y_pos
///
sfText *align_text_bottom(sfText *text, int y_pos);

///
/// Align the right of the sfText to x_pos
///
sfText *align_text_right(sfText *text, int x_pos);

///
/// Align the sfText X axis at the center of start_x and end_x
///
sfText *center_text_x(sfText *text, int start_x, int end_x);

///
/// Align the sfText Y axis at the center of start_y and end_y
///
sfText *center_text_y(sfText *text, int start_y, int end_y);

///
/// Helper function to create a sprite
/// If rect is not NULL, the texture rect will be set.
///
sfSprite *create_sprite(sfTexture *texture, sfIntRect *rect);

#endif //DISTRACT_GRAPHICS_H