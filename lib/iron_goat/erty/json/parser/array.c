/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** array_json
*/

#include <erty/json.h>

static bool json_read_array(struct json *conf, char const **buffer,
    struct json_array **arr)
{
    struct json tmp = {0};

    while (**buffer) {
        json_parse_withe_space(buffer);
        if (**buffer == ']') {
            *buffer += 1;
            conf->t = JSON_ARR;
            conf->v.array = *arr;
            return (true);
        } else if ((*buffer = estrchr(*buffer, ',')) == NULL) {
            ASSERT_RET("LibSeraph", "expected ',' after value [array]", false);
        }
        *buffer += 1;
        if (json_parse_value(&tmp, buffer) == false)
            return (false);
        if ((*arr)->push_back(arr, tmp) == -1)
            return (false);
        RESET_STRUCTURE_JSON(tmp);
    }
    ASSERT_RET("LibSeraph", "expected ']' to end the array", false);
}

bool json_parse_array(struct json *conf, char const **buffer)
{
    struct json_array *arr = NULL;
    struct json tmp = {0};

    if (**buffer != '[')
        return (false);
    if ((arr = json_vector_create()) == NULL)
        return (false);
    (*buffer)++;
    json_parse_withe_space(buffer);
    if (**buffer == ']') {
        (*buffer)++;
        conf->t = JSON_ARR;
        conf->v.array = arr;
        return (true);
    }
    if (json_parse_value(&tmp, buffer) == false)
        return (false);
    if (arr->push_back(&arr, tmp) == -1)
        return (-1);
    return (json_read_array(conf, buffer, &arr));
}