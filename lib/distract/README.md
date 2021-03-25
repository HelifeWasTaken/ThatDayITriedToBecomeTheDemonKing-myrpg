# Distract

## How to use

### Create a game with a window

```c
    #include "distract/game.h"
    #include "distract/window.h"

    game_t *game = create_game();

    if (game == NULL)
        return;
    game->mode = MODE(1280, 720, 32); // 1280x720, with 32 bit color depth
    game->window = create_standard_window(game->mode, "My Game");

    // Set the scene to load first
    set_pending_scene(game, MENU_SCENE);

    // Will loop while there are scenes to load, the global scene loop
    do {
        code = load_pending_scene(game);
        if (code != 0) // the exit code is non-zero, so we exit
            exit(code);
    } while (has_pending_scene(game));

    destroy_game(game);
```

### Create a new scene

Each scene must have a lifecycle.

A lifecycle is a function that will be called each time the scene is loaded.

The returned code will be propagated, and usually correspond to the exit code.

```c
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"

// The lifecycle of the play scene
int play_lifecycle(game_t *game)
{
    sfEvent event;

    // Until the scene is closed
    while (is_scene_updated(game)) {

        // poll events
        while (sfRenderWindow_pollEvent(game->window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(game->window);
            } else {
                // Send events to the entities
                transmit_event_to_scene(game, &event);
            }
        }

        // update each entities of the sprite
        update_scene(game);

        // clear the scene
        sfRenderWindow_clear(game->window, sfWhite);

        // draw each entities of the sprite
        draw_scene(game);

        // display the window
        sfRenderWindow_display(game->window);
    }

    // destroy the scene and the resources
    destroy_scene(game, true);

    return (0);
}
```

And we add it to our project header file:

```c
    // An enum with every scenes
    enum scene_id {
        PLAY_SCENE,
    };

    int play_lifecycle(game_t *game);    
```

You need to register the corresponding scene to the registry.

```c
    game_t *game = create_game();

    // ...

    register_scene(game, PLAY_SCENE, &play_lifecycle);

    // ...

    // game loop
```


### Create an entity

An entity is a single compartimentarized unit with data and behaviour.

You first need to describe your entity and data structure.

```c
    #include "distract/entity.h"

    // An enum with every entities
    enum entity_id {
        CUSTOMENTITY,
    };

    // The structure defining the entity
    typedef customentity {
        entity_t *entity;
        sfSprite *sprite;
    } customentity_t;

    // Below are several "hook" functions for the entity
    // All of them are optional

    void create_customentity(game_t *game, entity_t *entity);
    void destroy_customentity(game_t *game, entity_t *entity);
    void update_player(game_t *game, entity_t *entity);
    void draw_player(game_t *game, entity_t *entity);
```

Once you got your data structure, you can implement the functions:

```c
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"
#include "distract/graphics.h"
#include "stdlib.h"
#include "<yourproject>/entities.h"

// will be called when the entity is created
// if the `instance` property is NULL, the entity will not be created
void create_customentity(game_t *game, entity_t *entity)
{
    // allocate space for customentity_t
    customentity_t *customentity = malloc(sizeof(customentity_t));

    // if allocation fails
    if (customentity == NULL)
        return;

    // texture bounds
    sfIntRect rect = IRECT(0, 0, 300, 200);

    // create or fetch a texture in the registry and return it
    sfTexture *texture = create_texture(game, "assets/sprite.png", &rect);

    // link customentity->entity to entity for easier access
    customentity->entity = entity;

    // create a sprite from the texture
    customentity->sprite = create_sprite(texture, NULL);

    // attach our customentity structure to the entity
    entity->instance = customentity;
}

// will be called when the entity is destroyed
void destroy_customentity(game_t *game, entity_t *entity)
{
    customentity_t *customentity = entity->instance;

    sfSprite_destroy(customentity->sprite);
    free(customentity);
}

// will be called when the entity is updated
void update_player(game_t *game, entity_t *entity)
{
    customentity_t *customentity = entity->instance;

    // set the position of the sprite to the position of the entity
    sfSprite_setPosition(customentity->sprite, entity->pos);
}

// will be called when the entity is drawn
void draw_player(game_t *game, entity_t *entity)
{
    customentity_t *customentity = entity->instance;

    // draw the sprite
    sfRenderWindow_drawSprite(game->window, customentity->sprite, NULL);
}


// will be called when an event is transmitted to the entity
bool handle_player_events(game_t *game, entity_t *entity, sfEvent *event)
{
    customentity_t *customentity = entity->instance;

    sfIntRect *bounds = sfSprite_getGlobalBounds(customentity->sprite);

    if (event->type == sfEvtMouseButtonPressed) {

        sfMouseButtonEvent click = event->mouseButton;

        if (sfFloatRect_contains(&bounds, move.x, move.y) && click.button == sfMouseLeft) {
            printf("the player sprite has been clicked!");

            // the event is succesfully caught
            return (true);
        }
    }

    // the event has not been caught
    return (false);
}
```

You then need to register the entity to the entities' registry:

```c
    game_t *game = create_game();

    // ...

    register_entity(game, &ENTITY(
        CUSTOMENTITY,                 // the entity id
        &create_customentity,         // the function called when created
        &draw_customentity,           // the function called when drawn
        &destroy_customentity,        // the function called when destroyed
        &update_customentity,         // the function called when updated
        &handle_customentity_events   // the function called when events are called
    ));

    // ...

    // game loop
```

### Place an entity in a scene

#### Create a simple entity

```c
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"

// The lifecycle of the play scene
int play_lifecycle(game_t *game)
{
    sfEvent event;

    //...

    // Create an entity of type CUSTOMENTITY
    // The events/destroy will be automatically hooked
    create_entity(game, CUSTOMENTITY);

    // ...

    // Until the scene is closed
    while (is_scene_updated(game)) {
        // ...
    }

    destroy_scene(game, true); // the entity will be destroyed with the scene
}
```

#### Create an entity and set one of its properties

```c
#include "distract/game.h"
#include "distract/entity.h"
#include "distract/resources.h"

// The lifecycle of the play scene
int play_lifecycle(game_t *game)
{
    sfEvent event;

    //...

    // create the entity and get its instance
    entity_t *entity = create_entity(game, CUSTOMENTITY);

    // If entity failed to be created, exit with error
    if (entity != NULL)
        return (84);
    
    // The instance is garanteed to be non-NULL at this point
    customentity_t *customentity = entity->instance;

    // will tint red the entity sprite
    sfSprite_setColor(customentity->sprite, sfRed);

    // ...

    // Until the scene is closed
    while (is_scene_updated(game)) {
        // ...
    }

    destroy_scene(game, true); // the entity will be destroyed with the scene
}
```

### Get an existing entity

The `GET_ENTITY` macro will get the first sprite matching the entity type.

```c
customentity_t *customentity = GET_ENTITY(game, CUSTOMENTITY)->instance;

// ...
```

> WARNING: `GET_ENTITY(game, type)` may return `NULL` if no entity of the type exist!

### Get every entity of type

In the case where you have several entities matching the type,
you can get the entities with the `FOREACH_ENTITY_OF_TYPE(entity_type, entities, entity)` macro.

```c
FOREACH_ENTITY_OF_TYPE(CUSTOMENTITY, game->scene->entities, entity) {
    customentity_t *customentity = entity->instance;

    // ...
}   
```