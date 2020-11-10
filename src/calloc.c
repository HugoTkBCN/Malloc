/*
** EPITECH PROJECT, 2020
** calloc
** File description:
** .c
*/

#include "libmy_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    unsigned char *ptr = malloc(size * nmemb);

    if (ptr == NULL)
        return (NULL);
    for (size_t idx = 0; idx < size; idx++)
        ptr[idx] = 0;
    return (ptr);
}