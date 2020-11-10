/*
** EPITECH PROJECT, 2020
** reallocarray
** File description:
** .c
*/

#include "libmy_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (((nmemb >= (1UL << (sizeof(size_t) * 4)) ||
        size >= (1UL << (sizeof(size_t) * 4))) &&
        nmemb > 0 && SIZE_MAX / nmemb < size) ? NULL :
        realloc(ptr, size * nmemb));
}