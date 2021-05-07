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

int count_spells(battle_opponent_t *enemy)
{
    int spell_count = 0;

    for (int i = 0; enemy->spells[i].name != NULL; i++)
        spell_count++;
    return (spell_count);
}

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

int compare_spells(battle_spell_t *spell1, battle_spell_t *spell2)
{
    if (spell1->type == spell2->type)
        return (0);
    if (spell1->type == BST_SCISSOR && spell2->type == BST_PAPER)
        return (-1);
    if (spell1->type == BST_PAPER && spell2->type == BST_ROCK)
        return (-1);
    if (spell1->type == BST_ROCK && spell2->type == BST_SCISSOR)
        return (-1);
    return (1);
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
    int spell_cmp = compare_spells(manager->enemy_spell_attempt,
        manager->friend_spell_attempt);

    if (spell_cmp > 0 || spell_cmp == 0) {
        manager->source = manager->friend_attempter;
        manager->target = manager->enemy_attempter;
        manager->spell = manager->friend_spell_attempt;
    }
    if (spell_cmp < 0 || manager->is_mutual_attack) {
        manager->source = manager->enemy_attempter;
        manager->target = manager->friend_attempter;
        manager->spell = manager->enemy_spell_attempt;
    }
    manager->is_mutual_attack = (spell_cmp == 0);
    manager->source->mana -= manager->spell->mana;
    set_animable_animation(&manager->source->animable, manager->spell->anim);
    eprintf("%s -> %s: %s\n", manager->source->name, manager->target->name,
        manager->spell->name);
    return (0);
}