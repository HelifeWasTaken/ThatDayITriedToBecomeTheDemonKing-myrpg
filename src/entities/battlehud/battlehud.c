/*
** EPITECH PROJECT, 2020
** battlehud
** File description:
** Entity
*/

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

bool create_battlehud(game_t *game UNUSED, entity_t *entity)
{
    battlehud_t *battlehud = dcalloc(sizeof(battlehud_t), 1);
    sfIntRect rect = IRECT(0, 0, 608, 192);
    sfTexture *texture = create_texture(game, "asset/battlehud.png", &rect);

    D_ASSERT(battlehud, NULL, "Cannot load battlehud", false);
    battlehud->selected_spell_id = -1;
    battlehud->entity = entity;
    battlehud->clock = create_pausable_clock(game);
    D_ASSERT(battlehud->clock, NULL, "Cannot load battle hud clock", false);
    battlehud->sprite = create_sprite(texture, NULL);
    D_ASSERT(battlehud->sprite, NULL, "Cannot load battle hud sprite", false);
    sfSprite_setScale(battlehud->sprite, VEC2F(2, 2));
    entity->pos = VEC2F(game->mode.width/2 - 608, game->mode.height - 192 * 2);
    sfSprite_setPosition(battlehud->sprite, entity->pos);
    entity->instance = battlehud;
    entity->draw_on_gui = true;
    if (!create_battlehud_labels(game, battlehud))
        return (false);
    return (create_battlehud_buttons(game, battlehud));
}

void destroy_battlehud(game_t *game UNUSED, entity_t *entity)
{
    battlehud_t *battlehud = entity->instance;

    sfSprite_destroy(battlehud->sprite);
    destroy_pausable_clock(battlehud->clock);
    destroy_battlehud_labels(game, battlehud);
    free(battlehud);
}

void update_battlehud(game_t *game, entity_t *entity)
{
    battlehud_t *battlehud = entity->instance;

    update_battlehub_labels(game, battlehud);
    if (battlehud->manager->is_player_turn
    && !is_attack_anim_in_progress(battlehud->manager)) {
        battlehud->attack->is_enabled = true;
        battlehud->run->is_enabled = true;
    } else {
        battlehud->attack->is_enabled = false;
        battlehud->run->is_enabled = false;
    }
    tick_pausable_clock(battlehud->clock);
}

void draw_battlehud(game_t *game UNUSED, entity_t *entity UNUSED)
{
    battlehud_t *battlehud = entity->instance;

    sfRenderWindow_drawSprite(game->window, battlehud->sprite, NULL);
}

bool handle_battlehud_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    return (false);
}