/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** evector
*/

#ifndef __LIBERTY__EVECTOR__H__
#define __LIBERTY__EVECTOR__H__

#include <erty/opt.h>
#include <erty/estdlib.h>
#include <erty/string/esstring.h>
#include <erty/string/ecstring.h>

#define VECTOR(name) struct liberty_templated_vector_##name

#define VECTOR_PUSH_BACK_NAME(name) \
    liberty_templated_vector_push_back_##name

#define VECTOR_PUSH_BACK_DECLARATION(name) \
    static inline ssize_t VECTOR_PUSH_BACK_NAME(name)

#define VECTOR_CREATE_NAME(name) \
    liberty_templated_vector_create_##name

#define VECTOR_CREATE_DECLARATION(name) \
    static inline VECTOR(name) *VECTOR_CREATE_NAME(name)

#define VECTOR_CREATE(name) \
    liberty_templated_vector_create_##name()

#define VECTOR_CLEAR_NAME(name) \
    liberty_templated_vector_clear_##name

#define VECTOR_CLEAR_DECLARATION(name) \
    static inline void VECTOR_CLEAR_NAME(name)

#define INIT_VECTOR(name, type, del_member_fun) \
INIT_OPT(name, type); \
VECTOR(name) { \
    type *data; \
    size_t size; \
    size_t a_size; \
    ssize_t (*push_back)(VECTOR(name) **, type); \
    void (*_del)(type *); \
    void (*clear)(VECTOR(name) **); \
}; \
\
VECTOR_PUSH_BACK_DECLARATION(name)(VECTOR(name) **this, type add) \
{ \
    if ((*this)->a_size == (*this)->size) { \
        (*this)->a_size += (*this)->a_size ? (*this)->a_size / 10 : 10; \
        if ((*this)->size) \
            (*this)->data = erealloc((*this)->data, \
                sizeof(type) * (*this)->size, sizeof(type) * (*this)->a_size); \
        else \
            (*this)->data = emalloc(sizeof(type) * (*this)->a_size); \
        if ((*this)->data == NULL) \
            return (-1); \
    } \
    ememcpy(&(*this)->data[(*this)->size], &add, sizeof(type)); \
    (*this)->size++; \
    return ((*this)->size); \
} \
\
VECTOR_CLEAR_DECLARATION(name)(VECTOR(name) **this) \
{ \
    if ((*this)->_del) { \
        for (size_t i = 0; i < (*this)->size; i++) { \
            (*this)->_del(&(*this)->data[i]); \
        } \
    } \
    FREE((*this)->data); \
    (*this)->size = 0; \
    FREE(*this); \
} \
\
VECTOR_CREATE_DECLARATION(name)(void) \
{ \
    VECTOR(name) *this = ecalloc(sizeof(VECTOR(name)), 1); \
    \
    if (this == NULL) { \
        ASSERT("Vector", "Allocation failure"); \
        return (NULL); \
    } \
    this->push_back = VECTOR_PUSH_BACK_NAME(name); \
    this->_del = del_member_fun; \
    this->clear = VECTOR_CLEAR_NAME(name); \
    this->size = 0; \
    this->a_size = 0; \
    this->data = NULL; \
    return (this); \
}

#endif