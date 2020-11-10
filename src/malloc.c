/*
** EPITECH PROJECT, 2020
** malloc
** File description:
** .c
*/

#include "libmy_malloc.h"
#include "utils.h"

chunk_t *tampon = NULL;

void *malloc(size_t size)
{
    chunk_t *chunk = NULL;

    if (size == 0)
        return (NULL);
    else if (tampon == NULL)
        return ((tampon = init_memory(size)) == NULL ? NULL : tampon->address);
    chunk = get_free_chunk(size, tampon);
    if (chunk != NULL) {
        chunk->isfree = false;
        return (chunk->address);
    } else
        return ((chunk = create_chunk(size, tampon)) == NULL ? NULL :
        chunk->address);
    return (NULL);
}