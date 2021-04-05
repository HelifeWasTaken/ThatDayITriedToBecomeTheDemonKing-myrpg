/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** elinked
*/

#ifndef __LIBERTY__LINKED__H__
#define __LIBERTY__LINKED__H__

#include <erty/opt.h>
#include <erty/ectypes.h>
#include <erty/ealloc.h>
#include <erty/estdlib.h>
#include <erty/estdio.h>

#define LIST(name) struct liberty_templated_list_##name
#define LIST_EXTERN(name) struct liberty_templated_list_extern_##name

#define CREATE_LIST_DECLARATION(name) \
    liberty_templated_list_create_##name

#define CREATE_LIST(name) \
    CREATE_LIST_DECLARATION(name)()

// Node creation declaration
#define CREATE_NODE_DECLARATION(name) \
    liberty_templated_list_create_node_##name
#define CREATE_NODE(name, data) \
    CREATE_NODE_DECLARATION(name)(data)

// Head append

#define APPEND_TO_HEAD_DECLARATION(name) \
    liberty_templated_list_append_head_##name
#define APPEND_TO_HEAD(name, list, data) \
    APPEND_TO_HEAD_DECLARATION(name)(list, data)

// Tail append

#define APPEND_TO_TAIL_DECLARATION(name) \
    liberty_templated_list_append_tail_##name
#define APPEND_TO_TAIL(name, list, data) \
    APPEND_TO_TAIL_DECLARATION(name)(list, data)

// Index Append

#define APPEND_AT_INDEX_DECLARATION(name) \
    liberty_templated_list_append_index_##name
#define APPEND_AT_INDEX(name, list, data, pos) \
    APPEND_AT_INDEX_DECLARATION(name)(list, data, pos)

#define APPEND_AT_INDEX_SUB_FUNCTION_DECLARATION(name) \
    liberty_templated_list_append_index_subfunc_##name
#define APPEND_AT_INDEX_SUB_FUNCTION(name, list, data) \
    APPEND_AT_INDEX_SUB_FUNCTION_DECLARATION(name)(list, data)

// Tail delete

#define REMOVE_TO_TAIL_DECLARATION(name) \
    liberty_templated_list_delete_tail_##name
#define REMOVE_TO_TAIL(name, list) \
    REMOVE_TO_TAIL_DECLARATION(name)(list)

// Head delete

#define REMOVE_TO_HEAD_DECLARATION(name) \
    liberty_templated_list_delete_head_##name
#define REMOVE_TO_HEAD(name, list) \
    REMOVE_TO_HEAD_DECLARATION(name)(list)

// Index delete

#define REMOVE_AT_INDEX_DECLARATION(name) \
    liberty_templated_list_delete_at_index_##name
#define REMOVE_AT_INDEX(name, list, index) \
    REMOVE_AT_INDEX_DECLARATION(name)

#define CLEAR_LIST_DECLARATION(name) \
    liberty_templated_list_clear_##name
#define CLEAR_LIST(name, list) \
    CLEAR_LIST_DECLARATION(name)(list)

// Count nodes

#define COUNT_NODE_LIST_DECLARATION(name) \
    liberty_templated_list_count_node_##name
#define COUNT_NODE_LIST(name, list) \
    COUNT_NODE_LIST_DECLARATION(name)(list)

// Reverse list

#define REVERSE_LIST_DECLARATION(name) \
    liberty_templated_list_reverse_list_##name
#define REVERSE_LIST(name, list) \
    REVERSE_LIST_DECLARATION(name)(list)

// Call to internal delete function

#define INTERNAL_DEL_FUN_DECLARATION(name) \
    liberty_templated_list_internal_del_fun_##name

#define INTERNAL_DEL(name, list, delfun) \
    INTERNAL_DEL_FUN_DECLARATION(name)(list, delfun)

#define LIST_AT_DECLARATION(name) \
    liberty_templated_list_at_##name

#define LIST_AT(name, list, i) \
    LIST_AT_DECLARATION(name)(list, i)

// Functions

#define INIT_LIST(name, type, del_internal_fun) \
LIST(name) { \
    type data; \
    LIST(name) *prev; \
    LIST(name) *next; \
}; \
\
LIST_EXTERN(name) { \
    LIST(name) *list; \
    bool (*push_back)(LIST_EXTERN(name) **head, type data); \
    bool (*push_front)(LIST_EXTERN(name) **head, type data); \
    bool (*insert)(LIST_EXTERN(name) **head, type data, size_t i); \
    void (*pop_front)(LIST_EXTERN(name) **head); \
    void (*pop_back)(LIST_EXTERN(name) **head); \
    void (*erase)(LIST_EXTERN(name) **head, size_t i); \
    void (*clear)(LIST_EXTERN(name) **head); \
    void (*_del)(type *data); \
    OPT(name) (*at)(LIST_EXTERN(name) **head, size_t i); \
}; \
    \
static inline OPT(name) LIST_AT_DECLARATION(name)( \
    LIST_EXTERN(name) **this, size_t i) \
{ \
    LIST(name) *tmp = (*this)->list; \
    type useless; \
    \
    for (size_t idx = 0; tmp && idx < i; idx++) \
        tmp = tmp->next; \
    return (tmp ? OK(name, tmp->data) : ERR(name, useless)); \
} \
\
static inline void INTERNAL_DEL_FUN_DECLARATION(name)( \
        LIST(name) **node, void (*_del)(type *data)) \
{ \
    if (_del) \
        _del(&(*node)->data); \
    FREE(*node); \
} \
\
static inline LIST(name) *CREATE_NODE_DECLARATION(name)(type data) \
{ \
    LIST(name) *new_node = NULL; \
    \
    EXCALLOC(new_node, sizeof(LIST(name)), 1, NULL); \
    new_node->data = data; \
    return (new_node); \
} \
\
static inline void CLEAR_LIST_DECLARATION(name)( \
        LIST_EXTERN(name) **head) \
{ \
    LIST(name) *tmp = NULL; \
    \
    while ((*head)->list != NULL) {\
        tmp = (*head)->list; \
        (*head)->list = (*head)->list->next; \
        if ((*head)->_del) \
            (*head)->_del(&tmp->data); \
        FREE(tmp); \
    } \
} \
\
static inline bool APPEND_TO_HEAD_DECLARATION(name)( \
        LIST_EXTERN(name) **head, type data) \
{ \
    LIST(name) *new_node =  CREATE_NODE(name, data); \
    \
    if (!new_node) \
        return (false); \
    new_node->next = (*head)->list; \
    if ((*head)->list) { \
        (*head)->list->prev = new_node; \
    } \
    (*head)->list = new_node; \
    return (true); \
} \
\
static inline bool APPEND_TO_TAIL_DECLARATION(name)( \
    LIST_EXTERN(name) **head, type data) \
{ \
    LIST(name) *mv_ptr = (*head)->list; \
    \
    if ((*head)->list == NULL) \
        return ((*head)->push_front(head, data)); \
    for (; mv_ptr->next != NULL; mv_ptr = mv_ptr->next); \
        if ((mv_ptr->next = CREATE_NODE(name, data)) == NULL) \
        return (false); \
    mv_ptr->next->prev = mv_ptr; \
    return (true); \
} \
\
static inline bool \APPEND_AT_INDEX_SUB_FUNCTION_DECLARATION(name)( \
    LIST(name) *head, type data) \
{ \
    LIST(name) *new_node = CREATE_NODE(name, data); \
    LIST(name) *next = head->next; \
    \
    if (new_node == NULL) \
        return (false); \
    new_node->next = next; \
    head->next = new_node; \
    return (true); \
} \
\
static inline bool APPEND_AT_INDEX_DECLARATION(name)( \
        LIST_EXTERN(name) **head, type data, size_t index) \
{ \
    LIST(name) *mvptr = (*head)->list; \
    size_t i = 0; \
    \
    if (!index) \
        return ((*head)->push_front(head, data)); \
    if (!mvptr) \
        return (false); \
    for (; mvptr->next && i < index - 1; i++); \
        mvptr = mvptr->next; \
    if (!mvptr->next) { \
        efputs(stderr, "Reached end before index - TAIL - NULL"); \
        return (false); \
    } \
    return (APPEND_AT_INDEX_SUB_FUNCTION(name, mvptr, data)); \
} \
\
static inline void REMOVE_TO_TAIL_DECLARATION(name)( \
        LIST_EXTERN(name) **head) \
{ \
    LIST(name) *headptr = (*head)->list; \
    LIST(name) *last = NULL; \
    \
    if (!headptr) \
        return; \
    if (headptr->next == NULL) {\
        INTERNAL_DEL(name, &headptr, (*head)->_del); \
        return; \
    } \
    for (; headptr->next->next; headptr = headptr->next); \
        last = headptr->next; \
    headptr->next = NULL; \
    INTERNAL_DEL(name, &last, (*head)->_del); \
} \
\
static inline void REMOVE_TO_HEAD_DECLARATION(name)( \
        LIST_EXTERN(name) **head) \
{ \
    LIST(name) *tmp = (*head)->list; \
    \
    if (!tmp) \
        return; \
    (*head)->list = (*head)->list->next; \
    INTERNAL_DEL(name, &tmp, (*head)->_del); \
} \
\
static inline void REMOVE_AT_INDEX_DECLARATION(name)( \
        LIST_EXTERN(name) **head, size_t index) \
{ \
    LIST(name) *headptr = (*head)->list; \
    \
    for (size_t i = 0; i < index && headptr; headptr = headptr->next) \
        i++; \
    if (!headptr) \
        return; \
    if (!headptr->prev) { \
        (*head)->pop_front(head); \
        return; \
    } \
    if (!headptr->next) { \
        headptr->prev->next = NULL; \
        INTERNAL_DEL(name, &headptr, (*head)->_del); \
        return; \
    } \
    headptr->prev->next = headptr->next; \
    headptr->next->prev = headptr->prev; \
    INTERNAL_DEL(name, &headptr, (*head)->_del); \
} \
\
static inline size_t COUNT_NODE_LIST_DECLARATION(name)( \
        LIST_EXTERN(name) **head) \
{ \
    LIST(name) *tmp = (*head)->list; \
    size_t i = 0; \
    \
    for (; tmp; tmp = tmp->next) \
        i++; \
    return (i); \
} \
\
static inline void REVERSE_LIST_DECLARATION(name)( \
    LIST_EXTERN(name) **head) \
{ \
    LIST(name) *tmp = NULL; \
    LIST(name) *current = (*head)->list; \
    \
    while (current) { \
        tmp = current->prev; \
        current->prev = current->next; \
        current->next = tmp; \
        current = current->prev; \
    } \
    if (tmp) \
        (*head)->list = tmp->prev; \
} \
\
static inline LIST_EXTERN(name) *CREATE_LIST_DECLARATION(name)(void) \
{ \
    LIST_EXTERN(name) *self = NULL; \
    \
    EXCALLOC(self, sizeof(LIST_EXTERN(name)), 1, NULL); \
    self->list = NULL; \
    self->push_back = APPEND_TO_TAIL_DECLARATION(name); \
    self->push_front = APPEND_TO_HEAD_DECLARATION(name); \
    self->insert = APPEND_AT_INDEX_DECLARATION(name); \
    self->pop_front = REMOVE_TO_HEAD_DECLARATION(name); \
    self->pop_back = REMOVE_TO_TAIL_DECLARATION(name); \
    self->erase = REMOVE_AT_INDEX_DECLARATION(name); \
    self->clear = CLEAR_LIST_DECLARATION(name); \
    self->_del = del_internal_fun; \
    self->at = LIST_AT_DECLARATION(name); \
    return (self); \
}

#endif /* !__LIBERTY__LINKED__H__ */
