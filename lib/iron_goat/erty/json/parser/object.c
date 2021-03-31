/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** parse_json_object
*/

#include <erty/json.h>

static bool json_object_read_data(struct json_hashmap *objects,
                                    char const **buff)
{
    char *key = NULL;
    struct json tmp = {0};

    json_parse_withe_space(buff);
    if (**buff != '\"') {
        ASSERT("LibSeraph", "had trouble finding the start of the string");
        return (false);
    }
    (*buff)++;
    if (json_parse_string_internal(&key, buff) == false)
        return (false);
    json_parse_withe_space(buff);
    if (**buff != ':') {
        ASSERT("LibSeraph", "had trouble finding the ':' of the object");
        return (false);
    }
    (*buff)++;
    json_parse_withe_space(buff);
    if (json_parse_value(&tmp, buff) == false)
        return (false);
    return (objects->insert(&objects, JSON_TUPLE(key, tmp)));
}

bool json_parse_object_loop(struct json *conf, char const **buff,
                        struct json_hashmap *objects)
{
    while (**buff) {
        json_parse_withe_space(buff);
        if (**buff == '}') {
            conf->t = JSON_OBJ;
            conf->v.object = objects;
            (*buff)++;
            return (true);
        } else if ((*buff = estrchr(*buff, ',')) == NULL) {
            ASSERT("LibSeraph", "expected ',' after value [object]");
            return (false);
        }
        *buff += 1;
        json_parse_withe_space(buff);
        if (json_object_read_data(objects, buff) == false)
            return (false);
    }
    ASSERT("LibSeraph", "expected '}' to end the object");
    return (false);
}

bool json_parse_object(struct json *conf, char const **buff)
{
    struct json_hashmap *objects = NULL;

    if (**buff != '{')
        return (false);
    *buff += 1;
    json_parse_withe_space(buff);
    if ((objects = create_json_hashmap(5, ehasher)) == NULL)
        return (false);
    if (**buff == '}') {
        (*buff)++;
        conf->v.object = objects;
        conf->t = JSON_OBJ;
        return (true);
    }
    if (json_object_read_data(objects, buff) == false)
        return (false);
    return (json_parse_object_loop(conf, buff, objects));
}