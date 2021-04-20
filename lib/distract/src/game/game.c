/*
** EPITECH PROJECT, 2020
** game
** File description:
** Source code
*/

#include "distract/game.h"
#include "distract/entity.h"
#include "distract/hashmap.h"
#include "distract/sound.h"
#include "stdlib.h"
#include "distract/debug.h"
#include "distract/util.h"

game_t *create_game(void)
{
    game_t *game = dcalloc(1, sizeof(game_t));
    
    game->sound = create_sound_emitter(game);
    game->scene = allocate_scene();
    if (game == NULL || game->sound == NULL || game->scene == NULL) {
        print_error("Game initialisation failed");
        return (NULL);
    }
    return (game);
}

static void destroy_entity_infos(game_t *game)
{
    entity_info_t *entity_info = game->entities;
    entity_info_t *next = NULL;

    while (entity_info != NULL) {
        next = entity_info->next;
        free(entity_info);
        entity_info = next;
    }
    game->entities = NULL;
}

static void destroy_scene_infos(game_t *game)
{
    scene_info_t *scene_info = game->scenes;
    scene_info_t *next = NULL;

    while (scene_info != NULL) {
        next = scene_info->next;
        free(scene_info);
        scene_info = next;
    }
    game->scenes = NULL;
}

void destroy_game(game_t *game)
{
    if (game == NULL)
        return;
    if (game->window != NULL)
        sfRenderWindow_destroy(game->window);
    destroy_scene(game, true);
    deallocate_scene(game->scene);
    destroy_sound_emitter(game->sound);
    destroy_entity_infos(game);
    destroy_scene_infos(game);
    free(game);
}