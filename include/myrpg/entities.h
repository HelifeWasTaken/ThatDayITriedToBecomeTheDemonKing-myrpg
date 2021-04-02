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
    SETTING,
    VFX_SC,
    ATH,
    LAYER,
    HERO,
    VIEW,
    DEBUGMENU
};

//----------------------------------------

typedef enum view_type {
    HUD_VIEW,
    WORLD_VIEW
} view_type_t;

typedef struct view {
    sfView *view;
    sfView *hud_view;
    entity_t *entity;
    const struct hero *hero;
} view_t;

bool create_view(game_t *game, entity_t *entity);
void update_view(game_t *game, entity_t *entity);
void destroy_view(game_t *game, entity_t *entity);
void set_view_type(game_t *game, view_t *view, view_type_t type);

enum player_move {
    PLAYER_MOVE_DOWN,
    PLAYER_MOVE_LEFT,
    PLAYER_MOVE_RIGHT,
    PLAYER_MOVE_UP
};

typedef struct hero {
    entity_t *entity;
    pausable_clock_t *animation_clock;
    pausable_clock_t *movement_clock;
    sfSprite *sprite;
    const struct layer *collision;
} hero_t;

bool create_hero(game_t *game, entity_t *entity);
void update_hero(game_t *game, entity_t *entity);
void draw_hero(game_t *game, entity_t *entity);
void destroy_hero(game_t *game, entity_t *entity);
bool handle_hero_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED);

void player_move_up(hero_t *hero, sfIntRect *rect);
void player_move_down(hero_t *hero, sfIntRect *rect);
void player_move_left(hero_t *hero, sfIntRect *rect);
void player_move_right(hero_t *hero, sfIntRect *rect);

typedef struct ath {
    entity_t *entity;
    sfSprite *player_ath_sprite;
    sfVector2f ath_pos;
    sfSprite *button_sprite[6];
    view_t *view;
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

bool create_settings(game_t *game, entity_t *entity);
void update_settings(game_t *game, entity_t *entity);
void draw_settings(game_t *game, entity_t *entity);
void destroy_settings(game_t *game, entity_t *entity);
bool handle_settings_events(game_t *game, entity_t *entity, sfEvent *event);

bool create_scroll_bar(game_t *game, entity_t *entity);
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
bool create_vfx_scroll(game_t *game, entity_t *entity);
void update_vfx_scroll(game_t *game, entity_t *entity);
void draw_vfx_scroll(game_t *game, entity_t *entity);
void destroy_vfx_scroll(game_t *game, entity_t *entity);
bool handle_vfx_scroll_events(game_t *game, entity_t *entity, sfEvent *event);
void set_size_vox(game_t *game, vfx_scroll_t *scroll);
void set_size_mus(game_t *game, vfx_scroll_t *scroll);
void set_size_vfx(game_t *game, vfx_scroll_t *scroll);

typedef struct layer {
    vertex_map_t map;
    entity_t *entity;
} layer_t;

bool create_layer(game_t *game, entity_t *entity);
void draw_layer(game_t *game, entity_t *entity);
void destroy_layer(game_t *game, entity_t *entity);

typedef struct debugmenu {
    entity_t *entity;
    pausable_clock_t *clock;
    sfText *debugtext;
    view_t *view;
    bool enabled;
} debugmenu_t;

bool create_debugmenu(game_t *game, entity_t *entity);
void update_debugmenu(game_t *game, entity_t *entity);
void draw_debugmenu(game_t *game, entity_t *entity);
void destroy_debugmenu(game_t *game, entity_t *entity);
bool handle_debugmenu_events(game_t *game, entity_t *entity, sfEvent *event);
#endif /* DDBE0D45_A6F4_48A8_BD16_E3A1287341DF */
