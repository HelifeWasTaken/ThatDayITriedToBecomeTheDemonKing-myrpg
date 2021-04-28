/*
** EPITECH PROJECT, 2021
** entities
** File description:
** Source code
*/

#ifndef DDBE0D45_A6F4_48A8_BD16_E3A1287341DF
#define DDBE0D45_A6F4_48A8_BD16_E3A1287341DF

#include "distract/animable.h"
#include "distract/entity.h"
#include "myrpg/game.h"
#include "define.h"
#include "myrpg/map/map.h"
#include "myrpg/battle.h"
#include "erty/tuple.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include "myrpg/pnj.h"

enum arrow_keys { KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_UP };

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
    DIALOG,
    DIALOGBOX,
    DEBUGMENU,
    INVENTORY,
    SELECT,
    BATTLEHUD,
    BATTLEDUMMY,
    BATTLEMANAGER,
    GUI_BUTTON,
    GUI_LABEL,
    PNJ

};

//----------------------------------------

typedef struct gui_button {
    entity_t *entity;
    void (*on_click)(game_t *game, entity_t *entity);
    sfText *text;
    char *title;
    bool mouse_entered;
    bool clicked;
    bool is_centered;
    bool is_enabled;
} gui_button_t;

bool create_button(game_t *game, entity_t *entity);
void destroy_button(game_t *game, entity_t *entity);
void draw_button(game_t *game, entity_t *entity);
void update_button(game_t *game, entity_t *entity);
bool handle_button_events(game_t *game, entity_t *entity, sfEvent *event);

typedef struct gui_label {
    entity_t *entity;
    sfText *text;
    char *title;
    bool is_enabled;
} gui_label_t;

bool create_label(game_t *game, entity_t *entity);
void update_label(game_t *game, entity_t *entity);
void draw_label(game_t *game, entity_t *entity);
void destroy_label(game_t *game, entity_t *entity);
bool handle_label_events(game_t *game, entity_t *entity, sfEvent *event);

typedef enum view_type {
    HUD_VIEW,
    WORLD_VIEW
} view_type_t;

typedef struct view {
    entity_t *entity;
    const struct hero *hero;
} view_t;

bool create_view(game_t *game, entity_t *entity);
void update_view(game_t *game, entity_t *entity);
void destroy_view(game_t *game, entity_t *entity);

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
void trigger_battle_rand(game_t *game, hero_t *hero);
bool handle_hero_events(game_t *game UNUSED, entity_t *entity UNUSED,
                        sfEvent *event UNUSED);

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
bool handle_menu_events(game_t *game UNUSED, entity_t *entity UNUSED,
                        sfEvent *event UNUSED);

typedef struct player {
    entity_t *entity;
    pausable_clock_t *clock;
    // parsed_args_t args = my_parse_args(argc, argv);

    // if (my_char_in(args.flags, 'h')) {
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
    struct dialog *dialog;
    char pending_buffer[4096];
    unsigned char chunk_id;
    bool is_visible;
} dialogbox_t;

bool create_dialogbox(game_t *game, entity_t *entity);
void update_dialogbox(game_t *game, entity_t *entity);
void draw_dialogbox(game_t *game, entity_t *entity);
void destroy_dialogbox(game_t *game, entity_t *entity);
bool handle_dialogbox_events(game_t *game, entity_t *entity, sfEvent *event);
bool show_dialog(struct dialog *npc);
void hide_dialog(dialogbox_t *dialog);
void show_next_dialog(dialogbox_t *dialog);
void wrap_dialog_text(dialogbox_t *dialog);

typedef struct dialog {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
    hero_t *hero;
    dialogbox_t *box;
    char *name;
    char **messages;
} dialog_t;

bool create_dialog(game_t *game, entity_t *entity);
void update_dialog(game_t *game, entity_t *entity);
void draw_dialog(game_t *game, entity_t *entity);
void destroy_dialog(game_t *game, entity_t *entity);
bool handle_dialog_events(game_t *game, entity_t *entity, sfEvent *event);

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

typedef struct battlemanager {
    struct battlehud *hud;
    entity_t *entity;
    pausable_clock_t *clock;
    pausable_clock_t *attack_clock;
    battle_opponent_t enemies[10];
    battle_opponent_t friends[10];
    sfText *bard_talking;
    pausable_clock_t *bard_talking_clock;
    int enemies_count;
    int friends_count;
    bool is_player_turn;
    int exit_code;
} battlemanager_t;

bool create_battlemanager(game_t *game, entity_t *entity);
void update_battlemanager(game_t *game, entity_t *entity);
void draw_battlemanager(game_t *game, entity_t *entity);
void destroy_battlemanager(game_t *game, entity_t *entity);
bool handle_battlemanager_events(game_t *game, entity_t *entity,
    sfEvent *event);
int create_battlemanager_enemies(game_t *game, battlemanager_t *manager);
int create_battlemanager_friends(game_t *game, battlemanager_t *manager);
int create_battle_bard_talking(game_t *game, battlemanager_t *battlemanager);
int create_battle(game_t *game, battlemanager_t *battlemanager);
void animate_battlemanager_sprites(battlemanager_t *battlemanager);
void update_battle(game_t *game, battlemanager_t *battlemanager);
void destroy_battle(game_t *game UNUSED, battlemanager_t *battlemanager);
int attack_opponent(game_t *game, battle_opponent_t *source,
    battle_opponent_t *target, battle_spell_t *spell);
void set_battle_bard_text(battlemanager_t *battlemanager, const char *text);
const char *get_battle_random_bard_dialog(void);

typedef struct battlehud {
    entity_t *entity;
    pausable_clock_t *clock;
    sfSprite *sprite;
    gui_button_t *attack;
    gui_button_t *run;
    gui_label_t *hp_label;
    gui_label_t *lv_label;
    gui_label_t *mana_label;
    battlemanager_t *manager;
    int selected_spell_id;
} battlehud_t;

bool create_battlehud(game_t *game, entity_t *entity);
void update_battlehud(game_t *game, entity_t *entity);
void draw_battlehud(game_t *game, entity_t *entity);
void destroy_battlehud(game_t *game, entity_t *entity);
bool handle_battlehud_events(game_t *game, entity_t *entity, sfEvent *event);
bool create_battlehud_buttons(game_t *game, battlehud_t *entity);
bool create_battlehud_labels(game_t *game, battlehud_t *hud);
void update_battlehub_labels(game_t *game, battlehud_t *hud);
void destroy_battlehud_labels(game_t *game, battlehud_t *hud);

#endif /* DDBE0D45_A6F4_48A8_BD16_E3A1287341DF */
