/*
** EPITECH PROJECT, 2020
** sound
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/debug.h"
#include "distract/resources.h"
#include "SFML/Graphics.h"
#include "stdio.h"
#include "stdarg.h"

sfSound *create_sound(game_t *game, char *filepath)
{
    resource_t *resource = get_resource(game, filepath);
    sfSound *tmp;

    if (resource == NULL) {
        if ((tmp = sfSound_create()) == NULL) {
            print_error("Failed to init sound");
            return (NULL);
        }
        resource = create_resource(game, NULL, R_SOUND_BUFFER);
        if (resource == NULL)
            return (NULL);
        resource->sound_buffer = sfSoundBuffer_createFromFile(filepath);
        sfSound_setBuffer(tmp, resource->sound_buffer);
        resource = create_resource(game, filepath, R_SOUND);
        if (resource == NULL)
            return (NULL);
        resource->sound = tmp;
    }
    return (resource->sound);
}

sfMusic *create_music(game_t *game, char *filepath)
{
    resource_t *resource = get_resource(game, filepath);

    if (resource == NULL) {
        resource = create_resource(game, NULL, R_MUSIC);
        if (resource == NULL)
            return (NULL);
        if ((resource->music = sfMusic_createFromFile(filepath)) == NULL)
            print_error("Failed to init music");
    }
    return (resource->music);
}