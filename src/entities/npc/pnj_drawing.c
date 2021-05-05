/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** pnj_drawing.c
*/

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
#include "myrpg/pnj.h"
#include "myrpg/util.h"

void sort_pnj(pnj_t *pnj)
{
    bool sorted = false;
    struct pnj_data tmp = {0};

    do {
        sorted = true;
        for (usize_t i = 0; i + 1 < pnj->pnj_vector->size; i++) {
            if (pnj->pnj_vector->data[i].pos.y >
                    pnj->pnj_vector->data[i + 1].pos.y) {
                tmp = pnj->pnj_vector->data[i];
                    pnj->pnj_vector->data[i] = pnj->pnj_vector->data[i + 1];
                pnj->pnj_vector->data[i + 1] = tmp;
                sorted = false;
            }
        }
    } while (!sorted);
}

void update_pnj_foreach(pnj_t *pnj)
{
    sfIntRect rect;

    for (usize_t i = 0; i < pnj->pnj_vector->size; i++) {
        rect = sfSprite_getTextureRect(pnj->pnj_vector->data[i].sprite);
        rect.left += pnj->pnj_vector->data[i].rect_size.x;
        if (rect.left == (int)(pnj->pnj_vector->data[i].rect_size.x *
                    (pnj->pnj_vector->data[i].frame)))
            rect.left = 0;
        sfSprite_setTextureRect(pnj->pnj_vector->data[i].sprite, rect);
        pnj->pnj_vector->data[i].pos = sfSprite_getPosition(
                pnj->pnj_vector->data[i].sprite);
    }
}

void draw_npc_and_hero(game_t *game, pnj_t *pnj)
{
    usize_t i = 0;

    sort_pnj(pnj);
    for (; i < pnj->pnj_vector->size; i++) {
        if (pnj->pnj_vector->data[i].pos.y > pnj->hero->entity->pos.y)
            break;
        sfRenderWindow_drawSprite(game->window,
                pnj->pnj_vector->data[i].sprite, NULL);
    }
    draw_hero(game, pnj->hero->entity);
    for (; i < pnj->pnj_vector->size; i++) {
        sfRenderWindow_drawSprite(game->window,
                pnj->pnj_vector->data[i].sprite, NULL);
    }
}