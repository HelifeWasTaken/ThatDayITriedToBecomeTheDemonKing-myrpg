/*
** EPITECH PROJECT, 2020
** LibErty
** File description:
** e_arrconcat
*/

#include <erty/string/ecstring.h>
#include <stdio.h>
#include <erty/estdlib.h>

static size_t get_earrconcat_buff_size(const_cstr_t *array,
    const_cstr_t delimiter)
{
    size_t count;
    size_t size = 0;
    size_t sizedelim = (delimiter) ? estrlen(delimiter) : 0;

    for (count = 0; array[count]; count++)
        size += estrlen(array[count]);
    size += (sizedelim * (count - 1)) + 1;
    return (size);
}

cstr_t earrconcat(const_cstr_t *array, const_cstr_t delimiter)
{
    size_t sizebuff = get_earrconcat_buff_size(array, delimiter);
    cstr_t buff = emalloc(sizeof(char) * sizebuff);
    cstr_t ptr = buff;
    size_t index = 0;

    if (!buff)
        return (NULL);
    for (size_t i = 0; array[i] != NULL; i++) {
        estrcpy(buff + index, array[i]);
        index += estrlen(ptr + index);
        if (delimiter && array[i][0] && array[i + 1]) {
            estrcpy(buff + index, delimiter);
            index += estrlen(ptr + index);
        }
    }
    return (ptr);
}
