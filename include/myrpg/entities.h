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
#include "define.h"

enum entity_type {
    PLAYER,
    SCROLL,
    MENU,
    SETTING,
    VFX_SC,
};

//----------------------------------------

typedef struct menu {
    entity_t *entity;
    sfSprite *bg_sprite;
    sfSprite *button_sprite[3];
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

typedef struct scroll_bar {
    entity_t *entity;
    pausable_clock_t *clock;
    sfRectangleShape *scroll_bar;
} scroll_bar_t;

struct func_button {
    void (*fonc)(game_t *game);
};

typedef struct settings {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *background;
    sfSprite *ground;
    sfSprite *sprite_button[4];
} settings_t;

void create_settings(game_t *game, entity_t *entity);
void update_settings(game_t *game, entity_t *entity);
void draw_settings(game_t *game, entity_t *entity);
void destroy_settings(game_t *game, entity_t *entity);
bool handle_settings_events(game_t *game, entity_t *entity, sfEvent *event);

void create_scroll_bar(game_t *game, entity_t *entity);
void update_scroll_bar(game_t *game, entity_t *entity);
void draw_scroll_bar(game_t *game, entity_t *entity);
void destroy_scroll_bar(game_t *game, entity_t *entity);
bool handle_scroll_bar_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct vfx_scroll {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite_bar;
    sfSprite *scrolin;
    float percentage;
    void (*on_scroll)(game_t *game, struct vfx_scroll *scroll);
    sfText *text;
} vfx_scroll_t;

bool fonc_scroll_vfx(game_t *game, entity_t *entity);
void create_vfx_scroll(game_t *game, entity_t *entity);
void update_vfx_scroll(game_t *game, entity_t *entity);
void draw_vfx_scroll(game_t *game, entity_t *entity);
void destroy_vfx_scroll(game_t *game, entity_t *entity);
bool handle_vfx_scroll_events(game_t *game, entity_t *entity, sfEvent *event);
void set_size_vox(game_t *game, vfx_scroll_t *scroll);
void set_size_mus(game_t *game, vfx_scroll_t *scroll);
void set_size_vfx(game_t *game, vfx_scroll_t *scroll);
#endif /* DDBE0D45_A6F4_48A8_BD16_E3A1287341DF */
