/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** ehashmap
*/

#ifndef __LIBERTY__EHASHMAP__H__
#define __LIBERTY__EHASHMAP__H__

#include <erty/elinked.h>
#include <erty/ectypes.h>
#include <erty/tuple.h>

#define HASHMAP(name) \
    struct liberty_templated_hashmap_##name

#define TUPLE_NAME(name) \
    liberty_temlated_hashmap_tuple_intern_##name

#define HASHMAP_GETTER_NAME(name) \
    liberty_templated_hashmap_getter_##name

#define HASHMAP_GETTER_DECLARATION(name) \
    OPT(name) HASHMAP_GETTER_NAME(name)

#define HASHMAP_RESIZER_INTERNAL_NAME(name) \
    liberty_templated_hashmap_resize_internal_##name
#define HASHMAP_RESIZER_INTERNAL_DECLARATION(name) \
    bool HASHMAP_RESIZER_INTERNAL_NAME(name)

#define HASHMAP_RESIZER_NAME(name) \
    liberty_templated_hashmap_resize_##name
#define HASHMAP_RESIZER_DECLARATION(name) \
    bool HASHMAP_RESIZER_NAME(name)

#define HASHMAP_INSERT_NAME(name) \
    liberty_templated_hashmap_insert_##name
#define HASHMAP_INSERT_DECLARATION(name) \
    bool HASHMAP_INSERT_NAME(name)

#define HASHMAP_CLEAR_NAME(name) \
    liberty_templated_hashmap_clear_##name
#define HASHMAP_CLEAR_DECLARATION(name) \
    void HASHMAP_CLEAR_NAME(name)

#define HASHMAP_INIT_NAME(name) \
    liberty_templated_hashmap_init_##name
#define HASHMAP_INIT_DECLARATION(name) \
    bool HASHMAP_INIT_NAME(name)
#define CREATE_HASHMAP(name, map, size, hasher) \
    HASHMAP_INIT_NAME(name)(size, map, hasher)

#define INIT_HASHMAP(name, type, del_member_fun) \
INIT_LIST(name, TUPLE(name), del_member_fun); \
HASHMAP(name) { \
    u64_t (*hash)(const void *); \
    usize_t size; \
    usize_t bucket_count; \
    bool (*insert)(HASHMAP(name) *, TUPLE(name)); \
    void (*clear)(HASHMAP(name) *); \
    OPT(name) (*get)(HASHMAP(name) *, void *key); \
    LIST_EXTERN(name) *bucket; \
}; \
\
HASHMAP_GETTER_DECLARATION(name)(HASHMAP(name) *self, void *key) \
{ \
    uint64_t id = self->hash(key) % self->bucket_count; \
    LIST(name) *ptr = self->bucket[id].list; \
    TUPLE(name) tmp; \
    OPT(name) res; \
    \
    while (ptr) { \
        if (estrcmp((char *)key, ptr->data.key) == 0) { \
            tmp = (TUPLE(name)){ptr->data.key, ptr->data.data}; \
            res.is_ok = true; \
            res.value = tmp; \
            return (res); \
        } \
        ptr = ptr->next; \
    } \
    res.is_ok = false; \
    res.value = tmp; \
    return (res); \
} \
\
HASHMAP_RESIZER_INTERNAL_DECLARATION(name)(HASHMAP(name) *self, \
        LIST_EXTERN(name) **new_node, size_t i) \
{ \
    uint64_t id = 0; \
    LIST(name) *tmp = self->bucket[i].list; \
    LIST(name) *nxt = NULL; \
    \
    while (tmp) { \
        nxt = tmp->next; \
        id = self->hash(tmp->data.key) % self->bucket_count; \
        if (!(*new_node)[id].push_front(&(*new_node)[id], \
            (TUPLE(name)){tmp->data.key, tmp->data.data})) \
            return (false); \
        FREE(tmp); \
        tmp = nxt; \
    } \
    return (true); \
} \
\
HASHMAP_RESIZER_DECLARATION(name)(HASHMAP(name) *self) \
{ \
    LIST_EXTERN(name) *n_buck = NULL; \
    usize_t original = self->bucket_count; \
    \
    self->bucket_count *= 2; \
    EXCALLOC(n_buck, sizeof(LIST_EXTERN(name)), \
        self->bucket_count, false); \
    for (size_t i = 0; i < self->bucket_count; i++) \
        n_buck[i] = CREATE_LIST(name); \
    for (size_t i = 0; i < original; i++) \
        if (!HASHMAP_RESIZER_INTERNAL_NAME(name)(self, &n_buck, i)) \
            return (false); \
    FREE(self->bucket); \
    self->bucket = n_buck; \
    return (true); \
} \
\
HASHMAP_INSERT_DECLARATION(name)(HASHMAP(name) *self, \
        TUPLE(name) data) \
{ \
    usize_t v = self->hash(data.key) % self->bucket_count; \
    LIST(name) *ptr = self->bucket[v].list; \
    usize_t count = 0; \
    \
    if (data.key == NULL) \
        return (false); \
    if (HASHMAP_GETTER_NAME(name)(self, data.key).is_ok == true) { \
        DEBUG_PRINTF("ERROR: Key duplicate detected: %s", data.key); \
        return (false); \
    } \
    if (self->bucket[v].push_front(&self->bucket[v], data)) { \
        for (; ptr; ptr = ptr->next) \
            count++; \
            self->size++; \
        if ((count > 2 && (self->size >= self->bucket_count / 2)) \
            || count > 3) \
            return (HASHMAP_RESIZER_NAME(name)(self)); \
        return (true); \
    } \
    return (false); \
} \
\
HASHMAP_CLEAR_DECLARATION(name)(HASHMAP(name) *self) \
{ \
    for (usize_t i = 0; i < self->bucket_count; i++) \
        self->bucket[i].clear(&self->bucket[i]); \
    FREE(self->bucket); \
} \
\
HASHMAP_INIT_DECLARATION(name)(HASHMAP(name) *self, \
        usize_t bucket_count, u64_t (*hash)(const void *)) \
{ \
    *self = (HASHMAP(name)){ \
        .hash = hash, \
        .size = 0, \
        .bucket_count = bucket_count, \
        .insert = HASHMAP_INSERT_NAME(name), \
        .clear = HASHMAP_CLEAR_NAME(name), \
        .get = HASHMAP_GETTER_NAME(name), \
        .bucket = NULL \
    }; \
    EXCALLOC(self->bucket, \
        sizeof(LIST_EXTERN(name)), bucket_count, false); \
    for (size_t i = 0; i < bucket_count; i++) \
        self->bucket[i] = CREATE_LIST(name); \
    return (true); \
}

#endif /* !__LIBERTY__EHASHMAP__H__ */
