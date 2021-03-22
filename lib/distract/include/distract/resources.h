/*
** EPITECH PROJECT, 2020
** resources
** File description:
** Source code
*/

#ifndef DISTRACT_RESOURCES_H
#define DISTRACT_RESOURCES_H
#include "SFML/Graphics.h"
#include "SFML/Audio.h"
#include "distract/def.h"
#include "distract/game.h"

enum resource_type {
    R_TEXTURE,
    R_MUSIC,
    R_SOUND_BUFFER,
    R_SOUND,
    R_FONT
};

typedef struct resource {
    struct resource *next;
    struct resource *prev;
    enum resource_type type;
    char *path;
    union {
        sfTexture *texture;
        sfMusic *music;
        sfSoundBuffer *sound_buffer;
        sfSound *sound;
        sfFont *font;
    };
} resource_t;

resource_t *create_resource(game_t *game, char *file, enum resource_type type);
void destroy_resource(game_t *game, resource_t *resource);
resource_t *get_resource(game_t *game, char *file);
void destroy_resource_by_name(game_t *game, char *file);

sfTexture *create_texture(game_t *game, char *file, sfIntRect *rect);
void destroy_textures(int count, ...);

sfFont *create_font(game_t *game, char *filepath);
void destroy_fonts(int count, ...);

sfSound *create_sound(game_t *game, char *filepath);
sfMusic *create_music(game_t *game, char *filepath);

#define DESTROY_TEXTURES(...) \
    destroy_textures(ARGS_COUNT(# __VA_ARGS__), ## __VA_ARGS__)

#define DESTROY_FONTS(...) \
    destroy_fonts(ARGS_COUNT(# __VA_ARGS__), ## __VA_ARGS__)

#endif //DISTRACT_RESOURCES_H