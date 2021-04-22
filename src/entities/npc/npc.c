/*
** EPITECH PROJECT, 2020
** npc
** File description:
** Entity
*/

#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
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
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include "distract/math.h"

bool create_npc(game_t *game UNUSED, entity_t *entity)
{
    npc_t *npc = dcalloc(sizeof(npc_t), 1);
    sfIntRect rect = IRECT(0, 0, 16, 16);
    sfTexture *texture = create_texture(game, "asset/icon/talk.png", &rect);
    entity_t *dialog = get_entity(game, DIALOGBOX);

    D_ASSERT(npc, NULL, "Cannot create npc", false);
    D_ASSERT(texture, NULL, "Cannot create npc texture", false);
    D_ASSERT(dialog, NULL, "Cannot get dialogbox entity for npc", false);
    npc->entity = entity;
    npc->clock = create_pausable_clock(game);
    npc->sprite = create_sprite(texture, NULL);
    npc->dialog = dialog->instance;
    D_ASSERT(npc->clock, NULL, "Cannot create npc clock", false);
    D_ASSERT(npc->sprite, NULL, "Cannot create npc sprite", false);
    entity->instance = npc;
    entity->z = 100;
    return (true);
}

void destroy_npc(game_t *game UNUSED, entity_t *entity)
{
    npc_t *npc = entity->instance;

    sfSprite_destroy(npc->sprite);
    destroy_pausable_clock(npc->clock);
    free(npc);
}

void update_npc(game_t *game UNUSED, entity_t *entity)
{
    npc_t *npc = entity->instance;

    sfSprite_setPosition(npc->sprite, entity->pos);
    tick_pausable_clock(npc->clock);
}

void draw_npc(game_t *game UNUSED, entity_t *entity)
{
    npc_t *npc = entity->instance;
    entity_t *heroentity = get_entity(game, HERO);
    sfVector2f pos;

    if (npc->hero == NULL) {
        npc->hero = heroentity->instance;
        return;
    }
    pos = npc->hero->entity->pos;
    if (v2fdistance(&pos, &entity->pos) < 50)
        sfRenderWindow_drawSprite(game->window, npc->sprite, NULL);
}

bool handle_npc_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    npc_t *npc = entity->instance;
    entity_t *heroentity = get_entity(game, HERO);
    sfVector2f pos;

    if (npc->hero == NULL) {
        npc->hero = heroentity->instance;
        return (false);
    }
    pos = npc->hero->entity->pos;
    if (v2fdistance(&pos, &entity->pos) >= 50)
        return (false);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace
        && !npc->dialog->is_visible
        && npc->clock->time > 0.02f) {
        show_dialog(npc);
        npc->clock->time = 0;
        return (true);
    }
    return (false);
}
