/*
** EPITECH PROJECT, 2021
** getter
** File description:
** getter
*/

#include <erty/json.h>

bool json_getter_loop(struct json *self, char *path, struct json *value)
{
    if (path == NULL) {
        ASSERT("Json", "Unexpected unknown error occured");
        return (false);
    }
    switch (*path) {
        case '[':
            return (json_get_array(self, ++path, value));
        case '.':
            return (json_get_object(self, ++path, value));
        case '\0':
            *value = *self;
            return (true);
    }
    ASSERT("Json", "Expected: '\\0' or '.' or '[' but none appeared "
                    "make sure to start the string with a '.' or '['");
    return (false);
}

OPT(json) json_get(struct json *self, char *path, enum json_type type_expect)
{
    struct json value = {0};

    if (json_getter_loop(self, path, &value) == true) {
        if (value.t == type_expect) {
            return (OK(json, value));
        } else {
            ASSERT("Json", "Argument asked was found but"
                            " was of the wrong type");
            return (EXPLICIT_ERR(json, value));
        }
    }
    ASSERT("Json", "Argument asked was not found");
    return (EXPLICIT_ERR(json, value));
}

bool json_getptr(struct json *self, struct json *ptr,
                char *path, enum json_type type_expect)
{
    if (json_getter_loop(self, path, ptr) == true) {
        if (ptr->t == type_expect) {
            return (true);
        } else {
            ASSERT("Json", "Argument asked was found but"
                            " was of the wrong type");
            return (false);
        }
    }
    ASSERT("Json", "Argument asked was not found");
    return (false);
}

bool json_exist(struct json *self, char *path, enum json_type type_expect)
{
    struct json value = {0};

    if (json_getter_loop(self, path, &value) == true) {
        if (value.t == type_expect)
            return (true);
        else
            return (false);
    }
    return (false);
}