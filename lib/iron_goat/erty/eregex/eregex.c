/*
** EPITECH PROJECT, 2021
** LibErty
** File description:
** eregex
*/

#include <erty/eregex.h>
#include <erty/ectypes.h>

static int match_it(char *expr, char const *reg, char **endptr);

static int match_question_mark(char *expr, char const *reg, char **endptr)
{
    if (*reg == *expr && match_it(expr + 1, reg + 2, endptr))
        return (1);
    else
        return (match_it(expr, reg + 2, endptr));
}

static int match_prev_star(char const prev, char *expr,
        char const *reg, char **endptr)
{
    do {
        if (match_it(expr, reg, endptr))
            return (1);
    } while (*expr && (*expr++ == prev || prev == '.'));
    return (0);
}

static int match_it(char *expr, char const *reg, char **endptr)
{
    if (*reg == '\0' || (*reg == '$' && *(reg + 1) == '\0' && *expr == '\0')) {
        *endptr = expr;
        return (1);
    }
    if (*(reg + 1) == '?')
        return (match_question_mark(expr, reg, endptr));
    if (*(reg + 1) == '*')
        return (match_prev_star(*reg, expr, reg + 2, endptr));
    if ((*expr && *reg == '.') || (*expr && *reg == *expr))
        return (match_it(expr + 1, reg + 1, endptr));
    return (0);
}

int regex(char *expr, char const *reg, char **startptr, char **endptr)
{
    do {
        if (match_it(expr, reg, endptr)) {
            *startptr = expr;
            return (1);
        }
    } while (*expr++);
    return (0);
}
