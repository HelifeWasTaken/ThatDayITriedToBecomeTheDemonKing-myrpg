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
    battlemanager_t *manager = get_instance(game, BATTLEMANAGER);

    if (manager == NULL)
        return;
    manager->exit_code = 2;
    switch_to_scene(game, -1);
}

static void on_attack_click(game_t *game, entity_t *entity UNUSED)
{
    battlehud_t *hud = get_instance(game, BATTLEHUD);

    if (hud == NULL)
        return;
    hud->show_attacks = true;
}

static bool fill_buttons(game_t *game UNUSED, battlehud_t *hud)
{
    hud->attack->title = "Attack";
    hud->attack->entity->pos = VEC2F(hud->entity->pos.x + 100,
        hud->entity->pos.y + 100);
    hud->attack->on_click = on_attack_click;
    hud->run->title = "Run";
    hud->run->entity->pos = VEC2F(hud->entity->pos.x + 100,
        hud->entity->pos.y + 250);
    hud->run->on_click = on_run_click;
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
    return (fill_buttons(game, hud));
}