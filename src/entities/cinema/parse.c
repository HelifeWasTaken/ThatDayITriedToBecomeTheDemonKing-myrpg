/*
** EPITECH PROJECT, 2021
** cine
** File description:
** ma
*/

#include "myrpg/cinema.h"
#include "erty/estdlib.h"

void parse_space(char **buf)
{
    for (; **buf && (**buf == ' ' || **buf == '\t'); (*buf)++);
}

long long rpg_strtoll(char *str, char **endptr)
{
    long long result = 0;
    size_t i = 0;
    long long sign = eget_start_sign(str, &i);

    *endptr = str;
    parse_space(endptr);
    if (sign == -1)
        (*endptr)++;
    while (eis_num(**endptr)) {
        result += (**endptr) - '0';
        (*endptr)++;
        if (eis_num(**endptr)) {
            result *= 10;
        }
    }
    return (result * sign);
}

struct cinema_parser {
    const char *match;
    bool (*fun)(struct cinema **head, char *buf);
};

static const struct cinema_parser CINEMA_PRSR[] = {
    {
        .match = "move",
        .fun = parse_move_camera
    },
    {
        .match = "set",
        .fun = parse_set_camera
    },
    {
        .match = "disp",
        .fun = parse_disp_text
    },
    {
        .match = "new_scene",
        .fun = parse_new_scene
    }
};

static bool cinema_reader_command_internal(struct cinema **head, char *buf)
{
    size_t size = 0;

    parse_space(&buf);
    for (size_t i = 0; i < sizeof(CINEMA_PRSR) / sizeof(*CINEMA_PRSR); i++) {
        size = estrlen(CINEMA_PRSR[i].match);
        if (estrncmp(buf, CINEMA_PRSR[i].match, size) == 0 &&
            buf[size] == ' ') {
            return (CINEMA_PRSR[i].fun(head, buf + size));
        }
    }
    efprintf(stderr, "Failure: %s\n", buf);
    return (false);
}

bool cinema_reader_command(struct cinema **head, char const *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *buf = NULL;
    size_t size = 0;

    if (file == NULL) {
        efprintf(stderr, "%s: Could not be opened\n", filepath);
        return (false);
    }
    while (getline(&buf, &size, file) > 0) {
        if (cinema_reader_command_internal(head, buf) == false) {
            FREE(buf);
            fclose(file);
            efprintf(stderr, "Internal error in parser command\n");
            return (false);
        }
    }
    FREE(buf);
    fclose(file);
    return (true);
}
