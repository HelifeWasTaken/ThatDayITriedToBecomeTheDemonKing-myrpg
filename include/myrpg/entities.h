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
#include "myrpg/map/map.h"
#include "define.h"
#include "myrpg/map/map.h"
#include "SFML/Graphics.h"
#include "SFML/Window.h"

enum arrow_keys {
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_UP
};

// Everything related to layers
// except layer_manager is located in
// myrpg/map/map.h
enum entity_type {
    PLAYER,
    SCROLL,
    MENU,
    SETTING,
    VFX_SC,
    ATH,
    LAYER,
    LAYER_MANAGER,
    TILESET_LAYER_MANAGER,
    TILESET_LAYER,
    COLLISION_LAYER,
    OBJECT_LAYER_MANAGER,
    WARP,
    HERO,
    VIEW,
    NPC,
    DIALOGBOX,
    DEBUGMENU,
    INVENTORY,
    SELECT
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
    PLAYER_MOVE_UP,
    PLAYER_MOVE_END
};

typedef struct hero {
    entity_t *entity;
    pausable_clock_t *animation_clock;
    pausable_clock_t *movement_clock;
    sfSprite *sprite;
    double speed;
    const struct map_loader *layers;
    bool disable_collision;
} hero_t;

bool create_hero(game_t *game, entity_t *entity);
void update_hero(game_t *game, entity_t *entity);
void draw_hero(game_t *game, entity_t *entity);
void destroy_hero(game_t *game, entity_t *entity);
bool handle_hero_events(game_t *game UNUSED,
        entity_t *entity UNUSED, sfEvent *event UNUSED);

void update_hero_move(game_t *game UNUSED, hero_t *hero);
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
void update_button_handler(game_t *game UNUSED, entity_t *entity);

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
    sfSprite *sprite_button;
    sfText *txt;
    void (*fonc)(game_t *game, int i);
} settings_t;

bool create_settings(game_t *game, entity_t *entity);
void update_settings(game_t *game, entity_t *entity);
void draw_settings(game_t *game, entity_t *entity);
void destroy_settings(game_t *game, entity_t *entity);
bool handle_settings_events(game_t *game, entity_t *entity, sfEvent *event);
bool check_loading_btn(game_t *game, entity_t *entity);

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

sfText *init_text(game_t *game, entity_t *entity);
sfSprite *init_scrolin(game_t *game);
sfSprite *init_scroll(game_t *game, entity_t *entity);
bool fonc_scroll_vfx(game_t *game, entity_t *entity);
bool create_vfx_scroll(game_t *game, entity_t *entity);
void update_vfx_scroll(game_t *game, entity_t *entity);
void draw_vfx_scroll(game_t *game, entity_t *entity);
void destroy_vfx_scroll(game_t *game, entity_t *entity);
bool handle_vfx_scroll_events(game_t *game, entity_t *entity, sfEvent *event);
void set_size_vox(game_t *game, vfx_scroll_t *scroll);
void set_size_mus(game_t *game, vfx_scroll_t *scroll);
void set_size_vfx(game_t *game, vfx_scroll_t *scroll);

// More entities in the layer_manager_t include
// myrpg/map/map.h
// Entities in this .h need also to be registered
typedef struct map_loader {
    entity_t *entity;
    layer_manager_t manager;
} map_loader_t;

bool create_map_loader(game_t *game, entity_t *entity);
void destroy_map_loader(game_t *game, entity_t *entity);

bool create_layer(game_t *game, entity_t *entity);
void draw_layer(game_t *game, entity_t *entity);
void destroy_layer(game_t *game, entity_t *entity);

typedef struct dialogbox {
    entity_t *entity;
    pausable_clock_t *clock;
    sfRectangleShape *background;
    sfText *name_text;
    sfText *content_text;
    view_t *view;
    struct npc *npc;
    char pending_buffer[4096];
    unsigned char chunk_id;
    bool is_visible;
} dialogbox_t;

bool create_dialogbox(game_t *game, entity_t *entity);
void update_dialogbox(game_t *game, entity_t *entity);
void draw_dialogbox(game_t *game, entity_t *entity);
void destroy_dialogbox(game_t *game, entity_t *entity);
bool handle_dialogbox_events(game_t *game, entity_t *entity, sfEvent *event);
bool show_dialog(struct npc *npc);
void hide_dialog(dialogbox_t *dialog);
void show_next_dialog(dialogbox_t *dialog);
void wrap_dialog_text(dialogbox_t *dialog);

typedef struct npc {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
    hero_t *hero;
    dialogbox_t *dialog;
    char *name;
    char **messages;
} npc_t;

bool create_npc(game_t *game, entity_t *entity);
void update_npc(game_t *game, entity_t *entity);
void draw_npc(game_t *game, entity_t *entity);
void destroy_npc(game_t *game, entity_t *entity);
bool handle_npc_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct debugmenu {
    entity_t *entity;
    pausable_clock_t *clock;
    sfText *debugtext;
    view_t *view;
    bool enabled;
    hero_t *hero;
} debugmenu_t;

bool create_debugmenu(game_t *game, entity_t *entity);
void update_debugmenu(game_t *game, entity_t *entity);
void draw_debugmenu(game_t *game, entity_t *entity);
void destroy_debugmenu(game_t *game, entity_t *entity);
bool handle_debugmenu_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct inventory {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *over;
    view_t *view;
    bool is_visible;
    sfCircleShape *box;
    sfSprite **inventory;
    sfSprite *cursor_item;
    int mouse_state;
    bool is_deplacement;
    int item_id;
} inventory_t;

sfSprite *init_inventory(game_t *game, entity_t *entity);
bool create_inventory(game_t *game, entity_t *entity);
void update_inventory(game_t *game, entity_t *entity);
void draw_inventory(game_t *game, entity_t *entity);
void destroy_inventory(game_t *game, entity_t *entity);
bool handle_inventory_events(game_t *game, entity_t *entity, sfEvent *event);
bool init_inventory_item(game_t *game, entity_t *entity);
void inventory_management(game_t *game, entity_t *entity);

typedef const struct function {
    bool (*func)(UNUSED game_t *game, UNUSED entity_t *entity);
} function_t;

bool update_item(game_t *game, entity_t *entity);
void function_handler(UNUSED game_t *game, UNUSED entity_t *entity, int i);
bool func_btn_jar(UNUSED game_t *game, UNUSED entity_t *entity);
bool func_btn_inventory(UNUSED game_t *game, UNUSED entity_t *entity);
bool func_btn_setting(UNUSED game_t *game, UNUSED entity_t *entity);
bool func_btn_coin(UNUSED game_t *game, UNUSED entity_t *entity);
bool func_btn_save(UNUSED game_t *game, UNUSED entity_t *entity);
bool func_btn_quest(UNUSED game_t *game, UNUSED entity_t *entity);
bool update_cursor(game_t *game, entity_t *entity);

typedef struct mute_button {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
    void (*fonc)(game_t *game, bool vol);
    bool mute;
    sfText *str;
    char *text;
} mute_button_t;

sfSprite *init_background(game_t *game, UNUSED entity_t *entity);
sfText *init_text_btn(UNUSED game_t *game, UNUSED entity_t *entity);
sfSprite *init_ground(game_t *game, UNUSED entity_t *entity);
void set_size_sett(settings_t * setting);
void init_select_btn(game_t *game);
bool create_mute_button(game_t *game, entity_t *entity);
void update_mute_button(game_t *game, entity_t *entity);
void draw_mute_button(game_t *game, entity_t *entity);
void destroy_mute_button(game_t *game, entity_t *entity);
bool handle_mute_button_events(game_t *game, entity_t *entity, sfEvent *event);

#endif /* DDBE0D45_A6F4_48A8_BD16_E3A1287341DF */
