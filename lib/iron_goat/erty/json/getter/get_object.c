/*
** EPITECH PROJECT, 2021
** json
** File description:
** object
*/

#include <erty/json.h>

static bool json_check_object(struct json *self, char **path, char **obj)
{
    char *ptr = *path;

    if (self->t != JSON_OBJ) {
        ASSERT("Json", "One argument was expected to be an object but wasn't");
        return (false);
    }
    if (*ptr == '\0') {
        ASSERT("Json", "Unexpected end of string");
        return (false);
    }
    for (; *ptr && *ptr != '.' && *ptr != '['; ptr++);
    if ((*obj = estrndup(*path, ptr - *path)) == NULL) {
        ASSERT("Json", "Allocation error while trying to get json object");
        return (false);
    }
    *path = ptr;
    return (true);
}

bool json_get_object(struct json *self, char *path, struct json *value)
{
    char *obj = NULL;
    struct json_hashmap *object;
    OPT(json) tmp = {0};

    if (json_check_object(self, &path, &obj) == false)
        return (false);
    object = self->v.object;
    if ((tmp = object->get(&object, obj)).is_ok == false) {
        FREE(obj);
        return (false);
    }
    FREE(obj);
    return (json_getter_loop(&tmp.value, path, value));
}