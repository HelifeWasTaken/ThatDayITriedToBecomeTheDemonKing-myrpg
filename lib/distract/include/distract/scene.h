/*
** EPITECH PROJECT, 2020
** scene
** File description:
** Source code
*/

#ifndef DISTRACT_SCENE_H
#define DISTRACT_SCENE_H
#include "distract/game.h"
#include "distract/hashmap.h"
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
    int world_id;
    scene_info_t *info;
    struct entity *entities;
    hashmap_t *resources;
    struct gui_element *gui_elements;
    bool in_exit_state;
    int pending_scene_id;
    void *state;
} scene_t;

///
/// Call the draw function of every entities in the scene.
///
void draw_scene(game_t *game);

///
/// Call the update function of every entities in the scene.
///
void update_scene(game_t *game);

///
/// Destroy every entities in the scene.
/// Calls the destroy function of every entities in the scene.
/// If destroy_resources is set to true, registered resources will also be
/// freed.
///
void destroy_scene(game_t *game, bool destroy_resources);

///
/// Check if window is still open and scene is not exited.
///
bool is_scene_updated(game_t *game);

///
/// Exit the current scene and open the scene specified by the id.
///
void switch_to_scene(game_t *game, int id);

///
/// Do no exit the current scene but recreate it to load a new world
/// specified by an id
///
void switch_to_world(game_t *game, int id);

///
/// Set the scene to open when the current scene is closed.
///
void set_pending_scene(game_t *game, int id);

///
/// Check there is a scene that will be open once the current scene is closed.
///
bool has_pending_scene(game_t *game);

///
/// Registers a scene in the scene registry.
///
bool register_scene(game_t *game, int id, int (*lifecycle)(game_t *game));

///
/// Get scene info.
///
scene_info_t *get_scene_info(game_t *game, int id);

///
/// Execute the scene lifecycle of the pending scene.
///
int load_pending_scene(game_t *game);


///
/// Registers multiple scenes in the scene registry.
/// count is the number of scenes to register.
///
void register_scenes(game_t *game, int count, ...);

///
/// Send event to every entities in the scenes until one of the entities event
/// handlers return true.
///
bool transmit_event_to_scene(game_t *game, sfEvent *event);

#define REGISTER_SCENES(game, ...) \
    register_scenes(game, ARGS_COUNT(__VA_ARGS__), # __VA_ARGS__)

#endif //DISTRACT_SCENE_H
