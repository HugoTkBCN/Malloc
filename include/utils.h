/*
** EPITECH PROJECT, 2020
** utils
** File description:
** h
*/

#ifndef UTILS_H_
#define UTILS_H

#include "libmy_malloc.h"

void my_memcpy(chunk_t *, chunk_t *);
chunk_t *get_chunk(chunk_t *tmp, void *ptr);
chunk_t *get_free_chunk(size_t const size, chunk_t *tmp);
void *create_chunk(size_t const size, chunk_t *tmp);
void *init_memory(size_t const size);
chunk_t	*destroy_last(chunk_t *tmp, chunk_t *ret);
chunk_t *destroy_chunk(chunk_t *tmp);

#endif // !UTILS_H_