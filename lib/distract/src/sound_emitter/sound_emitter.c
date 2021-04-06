/*
** EPITECH PROJECT, 2021
** sound_emitter
** File description:
** Source code
*/

#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>
#include "distract/game.h"
#include "distract/sound_emitter.h"
#include "distract/resources.h"

sound_emitter_t *create_sound_emitter(game_t *game)
{
    sound_emitter_t *emitter = dcalloc(1, sizeof(sound_emitter_t));

    if (emitter == NULL)
        return (NULL);
    for (int i = 0; i < 32; i++) {
        emitter->volumes[i] = 100;
    }
    return (emitter);
}

void set_sound_volume(sound_emitter_t *emitter, unsigned char sound_type,
    float percentage)
{
    emitter->volumes[sound_type] = percentage;
}

bool play_sound(game_t *game, sound_emitter_t *emitter, int sound_type,
    char *file)
{
    float volume = sound_type == -1 ? 100 : emitter->volumes[sound_type];
    sfSound *sound = create_sound(game, file);

    if (sound == NULL)
        return (false);
    sfSound_setVolume(sound, volume);
    sfSound_play(sound);
    return (true);
}

bool play_music(game_t *game, sound_emitter_t *emitter, int sound_type,
    char *file)
{
    float volume = sound_type == -1 ? 100 : emitter->volumes[sound_type];
    sfMusic *music = create_music(game, file);

    if (music == NULL)
        return (false);
    sfMusic_setVolume(music, volume);
    sfMusic_play(music);
    return (true);
}

void destroy_sound_emitter(sound_emitter_t *emitter)
{
    free(emitter);
}