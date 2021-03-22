/*
** EPITECH PROJECT, 2020
** scene
** File description:
** Source code
*/

#ifndef DISTRACT_SCENE_H
#define DISTRACT_SCENE_H
#include "distract/game.h"
#include "distract/def.h"
#include "stdbool.h"

typedef struct scene_info {
    struct scene_info *next;
    int id;
    int (*lifecycle)(game_t *game);
    void *storage;
} scene_info_t;

typedef struct scene {
    int id;
    scene_info_t *info;
    struct entity *entities;
    struct resource *resources;
    struct gui_element *gui_elements;
    bool in_exit_state;
    int pending_scene_id;
    void *state;
} scene_t;

void draw_scene(game_t *game);
void update_scene(game_t *game);
void destroy_scene(game_t *game, bool destroy_resources);
bool is_scene_updated(game_t *game);
void switch_to_scene(game_t *game, int id);
void set_pending_scene(game_t *game, int id);
bool has_pending_scene(game_t *game);
void register_scene(game_t *game, int id, int (*lifecycle)(game_t *game));
scene_info_t *get_scene_info(game_t *game, int id);
int load_pending_scene(game_t *game);
void register_scenes(game_t *game, int count, ...);
bool transmit_event_to_scene(game_t *game, sfEvent *event);

#define REGISTER_SCENES(game, ...) \
    register_scenes(game, ARGS_COUNT(__VA_ARGS__), # __VA_ARGS__)

#endif //DISTRACT_SCENE_H