/*
** EPITECH PROJECT, 2020
** MY_RPG_PUBLIC
** File description:
** ath.c
*/

#include "distract/def.h"
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "distract/window.h"
#include "distract/debug.h"
#include "SFML/Window.h"
#include "myrpg/asset.h"
#include "SFML/Graphics.h"
#include "myrpg/entities.h"
#include "myrpg/define.h"
#include "stdlib.h"
#include "distract/util.h"
#include "myrpg/cinema.h"

bool handle_ath_events(game_t *game UNUSED,
    entity_t *entity UNUSED, sfEvent *event UNUSED)
{
    ath_t *ath = entity->instance;
    inventory_t *inventory = get_entity(game, INVENTORY)->instance;
    sfVector2f mouse_pos = get_mouse_pos(game);
    sfFloatRect buton_pos;

    if (GBL_IS_IN_CINEMATIC == true)
        return (false);
    D_ASSERT(inventory, NULL, "err inventory", false);
    for (unsigned int i = 0; i < 4; i++) {
        buton_pos = sfSprite_getGlobalBounds(ath->button_sprite[i]);
        if (sfFloatRect_contains(&buton_pos, mouse_pos.x,
            mouse_pos.y) == sfTrue) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                function_handler(game, entity, i);
                return (true);
            }
        }
    }
    return (false);
}

bool create_ath(game_t *game UNUSED, entity_t *entity)
{
    ath_t *ath = dcalloc(sizeof(ath_t), 1);
    sfIntRect rect = IRECT(0, 0, PLAYER_ATH_W, PLAYER_ATH_H);
    sfTexture *player_ath_texture = create_texture(game, PLAYER_ATH, &rect);
    sfFont *font = create_font(game, FONT);

    D_ASSERT(font && ath, false, "error font", false);
    ath->view = get_instance(game, VIEW);
    ath->lv = sfText_create();
    D_ASSERT((player_ath_texture && ath->view && ath->lv), false, "21", false);
    sfText_setFont(ath->lv, font);
    ath->player_ath_sprite = create_sprite(player_ath_texture, &rect);
    sfText_setPosition(ath->lv, VEC2F(200, 830));
    D_ASSERT(ath->player_ath_sprite, NULL, "error sprite ath", false);
    ath->ath_pos = VEC2F(0, PLAYER_ATH_POS_Y);
    D_ASSERT(create_ath_second_part(ath, game, NULL), false, "22", false);
    entity->instance = ath;
    ath->entity = entity;
    entity->z = 10000;
    entity->draw_on_gui = true;
    return (true);
}

void draw_ath(game_t *game UNUSED, entity_t *entity)
{
    ath_t *ath = entity->instance;

    SET_SPRITE_POS(ath->player_ath_sprite, ath->ath_pos);
    if (GBL_IS_IN_CINEMATIC == true)
        return;
    DRAW_SPRITE(game->window, ath->player_ath_sprite, NULL);
    for (unsigned int i = 0; i < 3; i++)
        if (get_game_state(game)->save.levels_done[i])
            sfRenderWindow_drawSprite(game->window, ath->ath_stones[i], NULL);
    for (unsigned int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(game->window, ath->button_sprite[i], NULL);
    sfRenderWindow_drawText(game->window, ath->lv, NULL);
}

void update_ath(game_t *game, entity_t *entity)
{
    ath_t *ath = entity->instance;

    ememset(ath->lv_text, 0, (sizeof(char) * 100));
    estrcpy(ath->lv_text, "Level ");
    eitoa(get_game_state(game)->save.player_lv, ath->lv_text + 6, "0123456789");
    sfText_setString(ath->lv, ath->lv_text);
}

void destroy_ath(game_t *game UNUSED, entity_t *entity)
{
    ath_t *ath = entity->instance;

    for (int i = 0; i < 4; i++)
        sfSprite_destroy(ath->button_sprite[i]);
    sfSprite_destroy(ath->player_ath_sprite);
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(ath->ath_stones[i]);
    free(ath);
}