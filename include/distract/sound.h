/*
** EPITECH PROJECT, 2021
** sound_emitter
** File description:
** Source code
*/

#ifndef D9549010_058C_4F95_B768_A6F8959E7D36
#define D9549010_058C_4F95_B768_A6F8959E7D36

#include "distract/hashmap.h"
#include "distract/resources.h"
#include "distract/util.h"
#include <SFML/Audio.h>
#include <SFML/Audio/Sound.h>
#include "stdlib.h"

typedef struct sound_emitter {
    float volumes[32];
} sound_emitter_t;

sound_emitter_t *create_sound_emitter(game_t *game);

void destroy_sound_emitter(sound_emitter_t *emitter);

float get_sound_volume(game_t *game, unsigned char sound_type);

void set_sound_volume(game_t *game, unsigned char sound_type,
    float percentage);

bool play_sound(game_t *game, int sound_type, char *file);

bool play_music(game_t *game, int sound_type, char *file);

#endif /* D9549010_058C_4F95_B768_A6F8959E7D36 */
