/*
** EPITECH PROJECT, 2020
** debugmenu
** File description:
** Entity
*/

#include "erty/eprintf.h"
#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "distract/util.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include <SFML/Graphics/Text.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

char *get_debug_message(game_t *game, debugmenu_t *debugmenu);
void handle_debug_keybind(game_t *game, sfKeyEvent *e, debugmenu_t *dbmenu);

bool create_debugmenu(game_t *game UNUSED, entity_t *entity)
{
    debugmenu_t *debugmenu = dcalloc(sizeof(debugmenu_t), 1);
    sfFont *font = create_font(game, "asset/homespun.ttf");

    debugmenu->view = get_instance(game, VIEW);
    debugmenu->hero = get_instance(game, HERO);
    D_ASSERT(debugmenu, NULL, "can't init debug menu", false);
    D_ASSERT(debugmenu->view && debugmenu->hero,
        false, "can't get view or hero for debugmenu menu", false);
    debugmenu->entity = entity;
    debugmenu->clock = create_pausable_clock(game);
    debugmenu->debugtext = sfText_create();
    sfText_setFont(debugmenu->debugtext, font);
    sfText_setColor(debugmenu->debugtext, sfWhite);
    sfText_setOutlineColor(debugmenu->debugtext, sfBlack);
    sfText_setOutlineThickness(debugmenu->debugtext, 2);
    sfText_setPosition(debugmenu->debugtext, VEC2F(10, 10));
    entity->instance = debugmenu;
    entity->z = 100000;
    entity->draw_on_gui = true;
    return (true);
}

void destroy_debugmenu(game_t *game UNUSED, entity_t *entity)
{
    debugmenu_t *debugmenu = entity->instance;

    sfText_destroy(debugmenu->debugtext);
    destroy_pausable_clock(debugmenu->clock);
    free(debugmenu);
}

void update_debugmenu(game_t *game UNUSED, entity_t *entity)
{
    debugmenu_t *debugmenu = entity->instance;
    char *message;

    if (!debugmenu->enabled)
        return;
    message = get_debug_message(game, debugmenu);
    sfText_setString(debugmenu->debugtext, message);
    free(message);
    tick_pausable_clock(debugmenu->clock);
}

void draw_debugmenu(game_t *game UNUSED, entity_t *entity)
{
    debugmenu_t *debugmenu = entity->instance;

    if (!debugmenu->enabled)
        return;
    sfRenderWindow_drawText(game->window, debugmenu->debugtext, NULL);
}

bool handle_debugmenu_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    debugmenu_t *debugmenu = entity->instance;

    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyF2)
            debugmenu->enabled = !debugmenu->enabled;
        if (debugmenu->enabled)
            handle_debug_keybind(game, &event->key, debugmenu);
    }
    return (false);
}
