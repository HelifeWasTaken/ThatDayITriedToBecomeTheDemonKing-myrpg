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
#include "distract/hashmap.h"

///
/// Type of resource in registry
///
enum resource_type {
    R_TEXTURE,
    R_MUSIC,
    R_SOUND_BUFFER,
    R_SOUND,
    R_FONT,
    R_VERTEX
};

///
/// Resource in the resources registry
///
typedef struct resource {
    enum resource_type type;
    char *path;
    union {
        sfTexture *texture;
        sfMusic *music;
        sfSoundBuffer *sound_buffer;
        sfSound *sound;
        sfFont *font;
        sfVertexArray *vao;
    };
} resource_t;

#define SAFE_RESOURCE_DESTROY(fun, res) \
    do { \
        if (res) \
            fun(res); \
    } while (0)

///
/// Create a resource of type from the file.
///
/// You would rather use other methods like `create_texture`, `create_font`,
/// `create_sound` instead
///
resource_t *create_resource(game_t *game, char *file, enum resource_type type);

///
/// Destroy the specified resource, freeing it.
///
void destroy_resource(game_t *game, resource_t *resource);

///
/// Get resource by name.
///
resource_t *get_resource(game_t *game, char *file);

///
/// Destroy resource by name, freeing it.
///
void destroy_resource_by_name(game_t *game, char *file);

///
/// Create and register a texture, with a size of rect.
/// If texture is already in memory, will return the existing instance.
///
sfTexture *create_texture(game_t *game, char *file, sfIntRect *rect);

///
/// Destroy textures.
/// count is the number of textures.
/// Other arguments are sfTexture*
///
void destroy_textures(int count, ...);

///
/// Create and register a font.
/// If font is already in memory, will return the existing instance.
///
sfFont *create_font(game_t *game, char *filepath);

///
/// Destroy fonts by instances.
/// count is the number of items.
/// Other arguments are sfFont*
///
void destroy_fonts(int count, ...);

///
/// Create and register a sound (and the appropriate soundbuffer automatically).
/// If sound is already in memory, will return the existing instance.
///
sfSound *create_sound(game_t *game, char *filepath);

///
/// Create and register a music.
/// If music is already in memory, will return the existing instance.
///
sfMusic *create_music(game_t *game, char *filepath);

///
/// Create and register a vertex array
/// If vertex array is already in memory, will return the existing instance.
///
sfVertexArray *create_vertex(game_t *game, char *filepath);

#define DESTROY_TEXTURES(...) \
    destroy_textures(ARGS_COUNT(# __VA_ARGS__), ## __VA_ARGS__)

#define DESTROY_FONTS(...) \
    destroy_fonts(ARGS_COUNT(# __VA_ARGS__), ## __VA_ARGS__)

#endif //DISTRACT_RESOURCES_H
