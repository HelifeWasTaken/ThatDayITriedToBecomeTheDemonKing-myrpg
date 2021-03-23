/*
** EPITECH PROJECT, 2021
** entities
** File description:
** Source code
*/

#ifndef DDBE0D45_A6F4_48A8_BD16_E3A1287341DF
#define DDBE0D45_A6F4_48A8_BD16_E3A1287341DF

#include "distract/entity.h"
#include "myrpg/game.h"

enum entity_type {
    PLAYER,
    MENU,
};

//----------------------------------------

typedef struct menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfSprite *play_sprite;
    sfTexture *play_texture;
} menu_t;

typedef struct player {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
} player_t;

void create_menu(game_t *game, entity_t *entity);
void destroy_menu(game_t *game, entity_t *entity);
void draw_menu(game_t *game UNUSED, entity_t *entity);
bool handle_menu_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED);

void create_player(game_t *game, entity_t *entity);
void update_player(game_t *game, entity_t *entity);
void draw_player(game_t *game, entity_t *entity);
void destroy_player(game_t *game, entity_t *entity);
bool handle_player_events(game_t *game, entity_t *entity, sfEvent *event);

#endif /* DDBE0D45_A6F4_48A8_BD16_E3A1287341DF */
