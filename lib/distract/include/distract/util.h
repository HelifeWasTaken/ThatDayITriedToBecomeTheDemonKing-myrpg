/*
** EPITECH PROJECT, 2021
** distract
** File description:
** util
*/

#ifndef E774BFD6_D06E_4AE0_ABA7_C9DAEB5BE2DF
#define E774BFD6_D06E_4AE0_ABA7_C9DAEB5BE2DF

#include "sys/types.h"

void *dcalloc(size_t count, size_t size);
void *dmalloc(size_t size);
void *dcalloc_s(size_t count, size_t size);
void *dmalloc_s(size_t size);
size_t dstrlen(char const *s);
char *dstrdup(char const *src);
int dstrcmp(char const *s1, char const *s2);

#endif /* E774BFD6_D06E_4AE0_ABA7_C9DAEB5BE2DF */
