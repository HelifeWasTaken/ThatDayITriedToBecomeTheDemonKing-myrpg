/*
** EPITECH PROJECT, 2021
** json
** File description:
** array
*/

#include <erty/json.h>

static bool json_check_array(enum json_type type, char *path)
{
    if (type != JSON_ARR) {
        ASSERT("Json", "One argument was expected to be an array but wasn't");
        return (false);
    }
    if (eis_num(*path) == false) {
        ASSERT("Json", "Expected a numeric value in json path array");
        return (false);
    }
    for (size_t i = 0; path[i]; i++) {
        if (path[i] == ']')
            return (true);
        if (eis_num(path[i]) == false) {
            ASSERT("Json", "Path array is wrongly formatted");
            return (false);
        }
    }
    ASSERT("Json", "Path array is wrongly formatted");
    return (false);
}

bool json_get_array(struct json *self, char *path, struct json *value)
{
    int64_t v = 0;
    struct json_array *array;

    if (json_check_array(self->t, path) == false)
        return (false);
    array = self->v.array;
    v = eatol(path).value;
    for (; eis_num(*path); path++);
    path++;
    if (v < 0) {
        ASSERT("Json", "Expected a positive value for the vector array");
        return (false);
    }
    if ((usize_t)v >= array->size) {
        ASSERT("Json", "Array argument is bigger that the vector array");
        return (false);
    }
    return (json_getter_loop(&array->data[v], path, value));
}