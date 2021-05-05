/*
** EPITECH PROJECT, 2021
** allocate_scene
** File description:
** Source code
*/

#include "distract/debug.h"
#include "distract/scene.h"
#include "distract/util.h"
#include <stdlib.h>

static size_t hash_resource_key(hashmap_t *map, void *key)
{
    char *str = (void *)key;
    size_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return (hash % map->capacity);
}

scene_t *allocate_scene(void)
{
    scene_t *scene = dcalloc(1, sizeof(scene_t));

    if (!scene)
        return (NULL);
    scene->resources = hashmap_create(50, &hash_resource_key);
    scene->id = -1;
    scene->pending_scene_id = -1;
    if (scene->resources == NULL) {
        print_error("Entity hashmap ressource could not be initted");
        return (NULL);
    }
    return (scene);
}

void deallocate_scene(scene_t *scene)
{
    hashmap_destroy(scene->resources);
    free(scene);
}