/*
** EPITECH PROJECT, 2021
** init
** File description:
** json_parser
*/

#include <erty/json.h>

static bool init_json_parsing(struct json *conf, char *buffer)
{
    const char *ptr = buffer;

    if (json_parse_value(conf, &ptr)) {
        FREE(buffer);
        return (true);
    }
    FREE(buffer);
    return (false);
}

bool json_parser(struct json *conf, char const *file)
{
    OPT(string) buffer;
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        ASSERT("LibSeraph", "file specified could not be opened");
        DEBUG_PRINTF("File: %s", file);
        return (false);
    } else if ((buffer = json_get_buffer(fd)).is_ok == false) {
        ASSERT("LibSeraph", "Buffer could not be read or allocation failed");
        close(fd);
        return (false);
    }
    close(fd);
    return (init_json_parsing(conf, buffer.value.to_buf(&buffer.value)));
}