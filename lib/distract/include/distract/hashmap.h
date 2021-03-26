/*
** EPITECH PROJECT, 2021
** distract
** File description:
** hashmap
*/

#ifndef DFFE5538_183A_4C1C_A75D_3FCEC26E05A1
#define DFFE5538_183A_4C1C_A75D_3FCEC26E05A1

#include <sys/types.h>

typedef struct hashmap {
  size_t size;
  size_t capacity;
  void **keys;
  void **values;
  size_t (*hasher)(struct hashmap *map, void *key);
} hashmap_t;

hashmap_t *hashmap_create(size_t capacity,
    size_t (*hasher)(hashmap_t *map, void *key));
void hashmap_destroy(hashmap_t *hash_map);
int hashmap_set(hashmap_t **hash_map_ptr, void *key, void *value);
void hashmap_unset(hashmap_t **map_ptr, void *key);
void *hashmap_get(hashmap_t *hash_map, void *key);
size_t hashmap_getindex(hashmap_t *hash_map, void *key);
int hashmap_resize(hashmap_t **hash_map_ptr);

#endif /* DFFE5538_183A_4C1C_A75D_3FCEC26E05A1 */
