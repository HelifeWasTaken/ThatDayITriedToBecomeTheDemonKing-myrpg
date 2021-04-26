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

int attack_opponent(game_t *game UNUSED, battle_opponent_t *source,
    battle_opponent_t *target, battle_spell_t *spell)
{
    if (source->mana < spell->mana)
        return (-1);
    source->mana -= spell->mana;
    target->health -= spell->efficiency;
    set_animable_animation(&source->animable, spell->anim);
    eprintf("%s -> %s: %s\n", source->name, target->name, spell->name);
    return (0);
}