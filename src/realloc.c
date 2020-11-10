/*
** EPITECH PROJECT, 2020
** realloc
** File description:
** .c
*/

#include "libmy_malloc.h"
#include "utils.h"

extern chunk_t *tampon;

void *realloc(void *ptr, size_t size)
{
    void *newptr = malloc(size);
    chunk_t	*old_chunk = NULL;
    chunk_t	*new = NULL;

    if (newptr == NULL) {
        free(ptr);
        return (NULL);
    }
    old_chunk = get_chunk(tampon, ptr);
    new = get_chunk(tampon, newptr);
    if (old_chunk == NULL || new == NULL)
        return (newptr);
    my_memcpy(new, old_chunk);
    free(ptr);
    return (newptr);
}