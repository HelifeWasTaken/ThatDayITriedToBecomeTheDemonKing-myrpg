/*
** EPITECH PROJECT, 2020
** entity
** File description:
** Source code
*/

#ifndef DISTRACT_ENTITY_H
#define DISTRACT_ENTITY_H
#include "SFML/Graphics.h"
#include "distract/game.h"
#include "distract/def.h"
#include "stdio.h"

typedef struct entity {
    struct entity *next;
    struct entity *prev;
    struct entity_info *info;
    sfVector2f pos;
    int type;
    int z;
    void *instance;
    bool (*do_collide_point)(struct entity *entity, sfVector2f *pos);
    bool (*do_collide_rect)(struct entity *entity, sfFloatRect *rect,
        sfFloatRect *overlap);
} entity_t;

typedef struct entity_info {
    struct entity_info *next;
    int type;
    void (*create)(game_t *game, entity_t *entity);
    void (*draw)(game_t *game, entity_t *entity);
    void (*destroy)(game_t *game, entity_t *entity);
    void (*update)(game_t *game, entity_t *entity);
    bool (*handle_event)(game_t *game, entity_t *entity, sfEvent *event);
} entity_info_t;

#define ENTITY(type, ...) \
    (entity_info_t) { NULL, type, __VA_ARGS__ }

entity_t *create_entity(game_t *game, int type);

entity_info_t *get_entity_info(game_t *game, int type);

void register_entity(game_t *game, entity_info_t *entity);

void add_to_entities(game_t *game, entity_t *entity);

void register_entities(game_t *game, entity_info_t **entities);

void draw_entity(game_t *game, entity_t *entity);

void update_entity(game_t *game, entity_t *entity);

void destroy_entity(game_t *game, entity_t *entity);

#define REGISTER_ENTITIES(game, ...) \
    register_entities(game, ((entity_info_t *[]){ 0, ## __VA_ARGS__, NULL })+1)

entity_t *get_next_entity_of_type(entity_t *entity, int type);

#define GET_ENTITY(game, entity_type) \
    get_next_entity_of_type(game->scene->entities, entity_type)

#define FOREACH_ENTITY_OF_TYPE(entity_type, entities, entity) \
    for (entity_t *entity = (entities->type == entity_type ? entities \
        : get_next_entity_of_type(entities, entity_type)) \
        ; entity != NULL; \
        entity = get_next_entity_of_type(entity, entity_type))

sfVector2f move_entity_towards(entity_t *entity, sfVector2f target,
    float distance);

#endif //DISTRACT_ENTITY_H