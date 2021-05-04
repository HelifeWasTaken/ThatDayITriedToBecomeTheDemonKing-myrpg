/*
** EPITECH PROJECT, 2021
** buttons
** File description:
** Source code
*/

#include "distract/entity.h"
#include "distract/debug.h"
#include "distract/game.h"
#include "distract/scene.h"
#include "distract/sound.h"
#include "myrpg/asset.h"
#include "myrpg/entities.h"

static void on_run_click(game_t *game, entity_t *entity UNUSED)
{
    switch_to_scene(game, -1);
}

static void on_attack_click(game_t *game, entity_t *entity UNUSED)
{
    battlehud_t *hud = get_instance(game, BATTLEHUD);

    if (hud == NULL)
        return;
    hud->selected_spell_id = 0;
}

static bool fill_buttons(game_t *game UNUSED, entity_t *entity,
    gui_button_t *attack, gui_button_t *run)
{
    attack->title = "Attack";
    attack->entity->pos = VEC2F(entity->pos.x + 100, entity->pos.y + 100);
    attack->on_click = on_attack_click;
    run->title = "Run";
    run->entity->pos = VEC2F(entity->pos.x + 100, entity->pos.y + 250);
    run->on_click = on_run_click;
    return (true);
}

bool create_battlehud_buttons(game_t *game, battlehud_t *hud)
{
    entity_t *tmp;
    gui_button_t *attack;
    gui_button_t *run;

    tmp = create_entity(game, GUI_BUTTON);
    D_ASSERT(tmp, NULL, "Cannot create battlehud buttons", false);
    attack = tmp->instance;
    tmp = create_entity(game, GUI_BUTTON);
    D_ASSERT(tmp, NULL, "Cannot create battlehud buttons", false);
    run = tmp->instance;
    hud->attack = attack;
    hud->run = run;
    return (fill_buttons(game, hud->entity, attack, run));
}