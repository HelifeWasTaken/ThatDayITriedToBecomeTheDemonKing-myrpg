/*
** EPITECH PROJECT, 2021
** attack
** File description:
** Source code
*/

#include "distract/animable.h"
#include "distract/util.h"
#include "erty/eassert.h"
#include "myrpg/battle.h"
#include "stdlib.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/asset.h"
#include "myrpg/define.h"
#include <SFML/Graphics/RenderWindow.h>

bool is_attack_anim_in_progress(battlemanager_t *manager)
{
    int anim;

    if (!is_animation_done(&manager->classic_hit_fx))
        return (true);
    for (int i = 0; i < manager->enemies_count; i++) {
        anim = get_animable_animation(&manager->enemies[i].animable);
        if (anim != BAT_ANIM_IDLE && anim != BAT_ANIM_DEATH)
            return (true);
    }
    for (int i = 0; i < manager->friends_count; i++) {
        anim = get_animable_animation(&manager->friends[i].animable);
        if (anim != BAT_ANIM_IDLE && anim != BAT_ANIM_DEATH)
            return (true);
    }
    return (false);
}

int end_attack(game_t *game UNUSED, battlemanager_t *manager)
{
    show_attack_fx(manager);
    manager->target->health -= manager->spell->efficiency;
    manager->source = NULL;
    manager->spell = NULL;
    manager->hud->selected_spell_id = -1;
    manager->clock->time = 0;
    return (0);
}

int start_attack(game_t *game UNUSED, battlemanager_t *manager)
{
    if (manager->source->mana < manager->spell->mana) {
        manager->source = NULL;
        manager->target = NULL;
        manager->spell = NULL;
        return (-1);
    }
    manager->source->mana -= manager->spell->mana;
    set_animable_animation(&manager->source->animable, manager->spell->anim);
    eprintf("%s -> %s: %s\n", manager->source->name, manager->target->name,
        manager->spell->name);
    return (0);
}