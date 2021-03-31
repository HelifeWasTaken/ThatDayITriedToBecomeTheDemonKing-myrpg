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
#include "myrpg/map.h"
#include "define.h"

enum arrow_keys {
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_UP
};

enum entity_type {
    PLAYER,
    SCROLL,
    MENU,
    ATH,
    LAYER,
    HERO,
    VIEW
};

//----------------------------------------

typedef struct view {
    sfView *view;
    entity_t *entity;
    const struct hero *hero;
} view_t;

bool create_view(game_t *game, entity_t *entity);
void update_view(game_t *game, entity_t *entity);
void destroy_view(game_t *game, entity_t *entity);

typedef struct hero {
    entity_t *entity;
    pausable_clock_t *animation_clock;
    pausable_clock_t *movement_clock;
    sfSprite *sprite;
    const struct layer *collision;
} hero_t;

#define HERO_KEY (int[]) {0, 100, 200, 300}

bool create_hero(game_t *game, entity_t *entity);
void update_hero(game_t *game, entity_t *entity);
void draw_hero(game_t *game, entity_t *entity);
void destroy_hero(game_t *game, entity_t *entity);
bool handle_hero_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED);

typedef struct ath {
    entity_t *entity;
    sfSprite *player_ath_sprite;
    sfVector2f ath_pos;
    sfSprite *button_sprite[6];
} ath_t;

bool create_ath(game_t *game, entity_t *entity);
void destroy_ath(game_t *game, entity_t *entity);
void draw_ath(game_t *game UNUSED, entity_t *entity);
bool handle_ath_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED);

typedef struct menu {
    entity_t *entity;
    sfSprite *bg_sprite;
    sfSprite *button_sprite[3];
} menu_t;

bool create_menu(game_t *game, entity_t *entity);
void destroy_menu(game_t *game, entity_t *entity);
void draw_menu(game_t *game UNUSED, entity_t *entity);
bool handle_menu_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED);

typedef struct player {
    entity_t *entity;
    pausable_clock_t *clock;
    //parsed_args_t args = my_parse_args(argc, argv);

    //if (my_char_in(args.flags, 'h')) {
    //       print_help();
    //    return (0);
    //}
    sfSprite *sprite;
} player_t;

bool create_player(game_t *game, entity_t *entity);
void update_player(game_t *game, entity_t *entity);
void draw_player(game_t *game, entity_t *entity);
void destroy_player(game_t *game, entity_t *entity);
bool handle_player_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct scroll_bar {
    entity_t *entity;
    pausable_clock_t *clock;
    sfRectangleShape *scroll_bar;
} scroll_bar_t;

bool create_scroll_bar(game_t *game, entity_t *entity);
void update_scroll_bar(game_t *game, entity_t *entity);
void draw_scroll_bar(game_t *game, entity_t *entity);
void destroy_scroll_bar(game_t *game, entity_t *entity);
bool handle_scroll_bar_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct layer {
    vertex_map_t map;
    entity_t *entity;
} layer_t;

bool create_layer(game_t *game, entity_t *entity);
void draw_layer(game_t *game, entity_t *entity);
void destroy_layer(game_t *game, entity_t *entity);

#endif /* DDBE0D45_A6F4_48A8_BD16_E3A1287341DF */
