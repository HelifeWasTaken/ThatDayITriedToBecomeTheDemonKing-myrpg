/*
** EPITECH PROJECT, 2020
** update_scene
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/input.h"
#include "distract/scene.h"
#include "stdio.h"
#include <SFML/System/Thread.h>

static void wait_thread_ends(game_t *game)
{
    entity_t *entity = game->scene->entities;
    entity_t *next;

    entity = game->scene->entities;
    while (entity != NULL) {
        next = entity->next;
        if (entity->use_multithreading) {
            sfThread_wait(entity->threadinfo->thread);
        }
        entity = next;
    }
}

void update_scene(game_t *game)
{
    entity_t *entity = game->scene->entities;
    bool use_threads = false;
    entity_t *next;

    while (entity != NULL) {
        next = entity->next;
        if (entity->use_multithreading) {
            update_entity_async(game, entity);
            use_threads = true;
        } else {
            update_entity(game, entity);
        }
        entity = next;
    }
    if (use_threads)
        wait_thread_ends(game);
    update_input(&game->input);
}