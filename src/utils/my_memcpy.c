/*
** EPITECH PROJECT, 2020
** memcpy
** File description:
** .c
*/

#include "libmy_malloc.h"

void my_memcpy(chunk_t *dest, chunk_t *src)
{
    size_t *src_ptr = (size_t *)src->address;
    size_t *dest_ptr = (size_t *)dest->address;

    for (int i = 0; i * sizeof(size_t) < src->size &&
    i * sizeof(size_t) < dest->size; i++)
        dest_ptr[i] = src_ptr[i];
}