/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** esplit
*/

#include <erty/string/ecstring.h>

void free_esplit(cstr_t *buf)
{
    if (!buf)
        return;
    for (size_t i = 0; buf[i]; i++)
        efree(buf[i]);
    efree(buf);
}

static void skip_char_copy(cstr_t str, char c, size_t *i)
{
    for (; str[*i] == c; (*i)++);
}

static size_t count_array(cstr_t str, char c)
{
    size_t count = 1;
    size_t i = 0;

    skip_char_copy(str, c, &i);
    for (; str[i]; i++) {
        if (str[i] == c) {
            count++;
            skip_char_copy(str, c, &i);
        }
    }
    return (count);
}

static cstr_t get_sub_string(cstr_t str, char c, size_t *i)
{
    size_t index2 = *i;
    char *new = NULL;

    for (; str[index2]; index2++)
        if (str[index2] == c)
            break;
    new = estrndup(str + *i, index2 - *i);
    *i = index2;
    return (new);
}

cstr_t *split(cstr_t str, char c)
{
    size_t i = 0;
    size_t j = 0;
    cstr_t *new_buff = emalloc(sizeof(cstr_t) * (count_array(str, c) + 1));

    if (new_buff == NULL)
        return (NULL);
    for (; str[i]; j++) {
        skip_char_copy(str, c, &i);
        if (!str[i])
            break;
        if ((new_buff[j] = get_sub_string(str, c, &i)) == NULL)
            return (NULL);
    }
    new_buff[j] = NULL;
    return (new_buff);
}