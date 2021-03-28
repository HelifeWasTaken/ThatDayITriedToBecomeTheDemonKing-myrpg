/*
** EPITECH PROJECT, 2021
** getstring
** File description:
** string
*/

#include <iron_goat/deser.h>

bool iron_goat_get_string(struct json *conf, size_t offset, void *data)
{
    char *s = estrdup(conf->v.string);
    char *dataptr = (char *)data;

    dataptr += offset;
    if (s == NULL) {
        ASSERT("json", "Allocation error");
        return (false);
    }
    SET_ATTRIBUTE(data, offset, sizeof(s), s);
    return (true);
}