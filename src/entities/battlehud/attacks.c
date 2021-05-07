/*
** EPITECH PROJECT, 2021
** attacks
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/resources.h"
#include "myrpg/entities.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>

static void on_attack_click(game_t *game, battlehud_atk_button_t *button)
{
    battlehud_t *hud = get_instance(game, BATTLEHUD);

    if (hud == NULL)
        return;
    hud->selected_spell_id = button->id;
}

bool create_attacks(game_t *game, battlehud_t *hud)
{
    sfTexture *rock_texture = create_texture(game, "asset/icon/rock.png", NULL);
    sfTexture *paper_texture = create_texture(game, "asset/icon/paper.png",
        NULL);
    sfTexture *scissor_texture = create_texture(game, "asset/icon/scissor.png",
        NULL);

    D_ASSERT(rock_texture, NULL, "null rock texture", false)
    D_ASSERT(paper_texture, NULL, "null rock texture", false)
    D_ASSERT(scissor_texture, NULL, "null rock texture", false)
    hud->atk_btn[0].btn = create_sprite(rock_texture, NULL);
    hud->atk_btn[1].btn = create_sprite(paper_texture, NULL);
    hud->atk_btn[2].btn = create_sprite(scissor_texture, NULL);
    for (int i = 0; i < 3; i++) {
        D_ASSERT(hud->atk_btn[i].btn, NULL, "null rock sprite", false)
        sfSprite_setScale(hud->atk_btn[i].btn, VEC2F(4, 4));
        sfSprite_setPosition(hud->atk_btn[i].btn, VEC2F(500 + i * 100, 850));
        hud->atk_btn[i].on_click = on_attack_click;
        hud->atk_btn[i].id = i;
    }
    return (true);
}

void destroy_attacks(game_t *game UNUSED, battlehud_t *hud)
{
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(hud->atk_btn[i].btn);
}

void draw_attacks(game_t *game UNUSED, battlehud_t *hud)
{
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(game->window, hud->atk_btn[i].btn, false);
}

void update_attacks(game_t *game UNUSED, battlehud_t *hud)
{
    for (int i = 0; i < 3; i++) {
        sfSprite_setColor(hud->atk_btn[i].btn, sfWhite);
        if (hud->atk_btn[i].is_mouse_over) {
            sfSprite_setColor(hud->atk_btn[i].btn,
                sfColor_fromRGB(10, 10, 10));
        }
        if (hud->atk_btn[i].clicked) {
            sfSprite_setColor(hud->atk_btn[i].btn,
                sfColor_fromRGB(125, 125, 125));
        }
    }
}