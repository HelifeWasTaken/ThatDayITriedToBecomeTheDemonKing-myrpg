/*
** EPITECH PROJECT, 2020
** dialogbox
** File description:
** Entity
*/

#include "erty/string/ecstring.h"
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
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>

static bool init_dialogbox(game_t *game, dialogbox_t *dialogbox)
{
    sfFont *font = create_font(game, FONT);

    D_ASSERT(font, NULL, "Can't get font", false)
    sfText_setColor(dialogbox->name_text, sfBlack);
    sfText_setFont(dialogbox->name_text, font);
    sfText_setColor(dialogbox->content_text, sfBlack);
    sfText_setFont(dialogbox->content_text, font);
    sfRectangleShape_setSize(dialogbox->background, VEC2F(1280, 200));
    sfText_setPosition(dialogbox->name_text, VEC2F(120, 110));
    sfText_setPosition(dialogbox->content_text, VEC2F(120, 170));
    sfRectangleShape_setPosition(dialogbox->background, VEC2F(100, 100));
    return (true);
}

static bool create_dialog_component(game_t *game, dialogbox_t *dialogbox)
{
    dialogbox->clock = create_pausable_clock(game);
    dialogbox->name_text = sfText_create();
    dialogbox->content_text = sfText_create();
    dialogbox->background = sfRectangleShape_create();
    D_ASSERT(dialogbox->clock, NULL,
        "Can't create dialog box clock", false);
    D_ASSERT(dialogbox->name_text, NULL,
        "Can't create dialog box name", false);
    D_ASSERT(dialogbox->content_text, NULL,
        "Can't create dialog content", false);
    D_ASSERT(dialogbox->background, NULL,
        "Can't create dialog box bg", false);
    return (true);
}

bool create_dialogbox(game_t *game UNUSED, entity_t *entity)
{
    dialogbox_t *dialogbox = dcalloc(sizeof(dialogbox_t), 1);
    entity_t *viewentity = get_entity(game, VIEW);

    D_ASSERT(viewentity, NULL, "Can't get view", false)
    D_ASSERT(dialogbox, NULL, "Can't create dialog box", false)
    dialogbox->entity = entity;
    if (create_dialog_component(game, dialogbox) == false)
        return (false);
    dialogbox->is_visible = false;
    dialogbox->view = viewentity->instance;
    D_ASSERT(init_dialogbox(game, dialogbox), false,
        "Can't initialize dialog box", false)
    entity->instance = dialogbox;
    entity->z = 1000000000;
    entity->draw_on_gui = true;
    return (true);
}
