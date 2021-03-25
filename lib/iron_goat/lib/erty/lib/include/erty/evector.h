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

    #define VECTOR_ERASE_NAME(name) \
        liberty_templated_vector_erase_##name

    #define VECTOR_ERASE_DECLARATION(name) \
        static inline ssize_t VECTOR_ERASE_NAME(name)

    #define VECTOR_AT_NAME(name) \
        liberty_templated_vector_at_##name

    #define VECTOR_AT_DECLARATION(name) \
        static inline OPT(name) VECTOR_AT_NAME(name)

    #define VECTOR_INSERT_NAME(name) \
        liberty_templated_vector_insert_##name

    #define VECTOR_INSERT_DECLARATION(name) \
        static inline ssize_t VECTOR_INSERT_NAME(name)

    #define INIT_VECTOR(name, type, del_member_fun) \
        INIT_OPT(name, type); \
        VECTOR(name) { \
            type *data; \
            size_t size; \
            ssize_t (*push_back)(VECTOR(name) **, type); \
            void (*_del)(type *); \
            ssize_t (*erase)(VECTOR(name) **, size_t idx); \
            void (*clear)(VECTOR(name) **); \
            ssize_t (*insert)(VECTOR(name) **, type, size_t idx); \
            OPT(name) (*at)(VECTOR(name) **, size_t idx); \
        }; \
        \
        VECTOR_AT_DECLARATION(name)(VECTOR(name) **this, size_t idx) \
        { \
            if (idx > (*this)->size) \
                return (EXPLICIT_ERR(name, (*this)->data[(*this)->size])); \
            return (OK(name, (*this)->data[idx])); \
        } \
        \
        VECTOR_PUSH_BACK_DECLARATION(name)(VECTOR(name) **this, type add) \
        { \
            type *tmp = NULL; \
            \
            EXCALLOC(tmp, sizeof(type), (*this)->size + 1, -1); \
            for (size_t i = 0; i < (*this)->size; i++) \
                ememcpy(&tmp[i], &(*this)->data[i], sizeof(type)); \
            ememcpy(&tmp[(*this)->size], &add, sizeof(type)); \
            FREE((*this)->data); \
            (*this)->data = tmp; \
            (*this)->size++; \
            return ((*this)->size); \
        } \
        \
        VECTOR_INSERT_DECLARATION(name)(VECTOR(name) **this, type toadd, \
                                        size_t idx) \
        { \
            type *tmp = NULL; \
            size_t i = 0; \
            size_t i2 = 0; \
            \
            if ((*this)->size <= idx) \
                return (-1); \
            EXCALLOC(tmp, sizeof(type), (*this)->size + 1, -1); \
            for (; i != idx; i++) \
                ememcpy(&tmp[i], &(*this)->data[i], sizeof(type)); \
            ememcpy(&tmp[i], &toadd, sizeof(type)); \
            i2 = i; \
            for (i += 1; i < (*this)->size + 1; i++) { \
                ememcpy(&tmp[i], &(*this)->data[i2], sizeof(type)); \
                i2++; \
            } \
            FREE((*this)->data); \
            (*this)->size = i; \
            (*this)->data = tmp; \
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
        VECTOR_ERASE_DECLARATION(name)(VECTOR(name) **this, size_t idx) \
        { \
            type *tmp = NULL; \
            size_t i = 0; \
            \
            if ((*this)->size <= idx) \
                return (-1); \
            EXCALLOC(tmp, sizeof(type), (*this)->size - 1, -1); \
            for (; i != idx; i++) \
                ememcpy(&tmp[i], &(*this)->data[i], sizeof(type)); \
            if ((*this)->_del) \
                (*this)->_del(&(*this)->data[i]); \
            i++; \
            for (; i < (*this)->size; i++) \
                ememcpy(&tmp[i], &(*this)->data[i], sizeof(type)); \
            FREE((*this)->data); \
            (*this)->data = tmp; \
            (*this)->size = i; \
            return ((*this)->size); \
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
            this->erase = VECTOR_ERASE_NAME(name); \
            this->clear = VECTOR_CLEAR_NAME(name); \
            this->insert = VECTOR_INSERT_NAME(name); \
            this->at = VECTOR_AT_NAME(name); \
            this->size = 0; \
            this->data = NULL; \
            return (this); \
        }

#endif