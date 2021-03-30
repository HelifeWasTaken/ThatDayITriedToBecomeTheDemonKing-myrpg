/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** esstring
*/

#ifndef __LIBERTY__SSTRING__H__
    #define __LIBERTY__SSTRING__H__

    #include <erty/ectypes.h>
    #include <erty/string/ecstring.h>
    #include <erty/opt.h>

    typedef struct string_class string_t;

    struct string_class {
        cstr_t  str;
        size_t  size;
        ssize_t (*assign)(string_t *this, const_cstr_t cstring);
        ssize_t (*assign_n)(string_t *self, const_cstr_t s, size_t n);
        ssize_t (*append)(string_t *this, const_cstr_t cstring);
        ssize_t (*append_n)(string_t *this, const_cstr_t cstring, size_t n);
        char   *(*at)(const string_t *this, size_t pos);
        i32_t   (*compare)(const string_t *this, const_cstr_t cstring);
        i32_t   (*ncompare)(const string_t *this, const_cstr_t cstring,
                            size_t n);
        char   *(*to_buf)(string_t *this);
        ssize_t (*print)(const string_t *this);
        void    (*free)(string_t *this);
    };

    void free_sstr(string_t *this);
    ssize_t assign_cstr(string_t *this, const_cstr_t cstring);
    ssize_t assign_n_from_cstr(string_t *this, const_cstr_t s, size_t n);
    ssize_t append_cstr(string_t *this, const_cstr_t cstring);
    ssize_t append_n_from_cstr(string_t *this, const_cstr_t s, size_t n);
    cstr_t at_sstr(const string_t *this, size_t pos);
    i32_t compare_cstr(const string_t *this, const_cstr_t cstring);
    i32_t ncompare_cstr(const string_t *this, const_cstr_t cstring, size_t n);
    cstr_t sstr_to_buf(string_t *this);
    ssize_t print_sstr(const string_t *this);

    string_t init_string(cstr_t buffer);

    OPT(string) json_get_buffer(const int fd);

#endif /* !__LIBERTY__SSTRING__H__ */