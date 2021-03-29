/*
** EPITECH PROJECT, 2021
** distract
** File description:
** stdutil
*/

#include "distract/debug.h"
#include "stdlib.h"
#include "sys/types.h"
#include <SFML/System.h>
#include <SFML/System/Time.h>

void *dcalloc(size_t count, size_t size)
{
    void *ptr = malloc(count * size);
    unsigned char *bytes = (unsigned char *)ptr;

    if (ptr == NULL)
        return (NULL);
    size *= count;
    while (size) {
        bytes[size - 1] = 0;
        size--;
    }
    return (ptr);
}

void *dmalloc(size_t size)
{
    return (malloc(size));
}

void *dcalloc_s(size_t count, size_t size)
{
    void *ptr = NULL;
    sfTime delay = { 1000 };

    if ((ptr = dcalloc(count, size)) == NULL) {
        print_error("Memory allocation error. "
                    "You may need to close other applications.");
        while ((ptr = dcalloc(count, size)) == NULL)
            sfSleep(delay);
    }
    return (ptr);
}

void *dmalloc_s(size_t size)
{
    void *ptr = NULL;
    sfTime delay = { 1000 };

    if ((ptr = malloc(size)) == NULL) {
        print_error("Memory allocation error. "
                    "You may need to close other applications.");
        while ((ptr = malloc(size)) == NULL)
            sfSleep(delay);
    }
    return (ptr);
}