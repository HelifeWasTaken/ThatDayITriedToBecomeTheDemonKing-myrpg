/*
** EPITECH PROJECT, 2021
** distract
** File description:
** hashmap
*/

#ifndef DFFE5538_183A_4C1C_A75D_3FCEC26E05A1
#define DFFE5538_183A_4C1C_A75D_3FCEC26E05A1

#include <sys/types.h>
#include <stdbool.h>
#include "distract/util.h"

struct hashmap_list {
    char *key;
    void *value;
    struct hashmap_list *next;
};

struct hashmap_bucket {
    struct hashmap_list *data;
};

typedef struct hashmap {
    size_t size;
    size_t capacity;
    struct hashmap_bucket *bucket;
    size_t (*hasher)(struct hashmap *map, void *key);
} hashmap_t;

hashmap_t *hashmap_create(size_t capacity,
        size_t (*hasher)(hashmap_t *map, void *key));
void hashmap_destroy(hashmap_t *hash_map);
int hashmap_set(hashmap_t **hash_map_ptr, void *key, void *value);
void hashmap_unset(hashmap_t **map_ptr, void *key);
void *hashmap_get(hashmap_t *hash_map, void *key);
void *hashmap_getindex(hashmap_t *hash_map, void *key);
int hashmap_resize(hashmap_t **hash_map_ptr);
bool insert_hashmap_bucket_front(struct hashmap_list **list,
    struct hashmap_list *node);
struct hashmap_list *hashmap_create_node(struct hashmap_list *new);
bool check_need_resize_hashmap(hashmap_t **self);

#endif /* DFFE5538_183A_4C1C_A75D_3FCEC26E05A1 */
