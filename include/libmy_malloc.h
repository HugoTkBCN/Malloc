/*
** EPITECH PROJECT, 2020
** libmy_malloc
** File description:
** .h
*/

#ifndef LIBMY_MALLOC_H
#define LIBMY_MALLOC_H

#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>

typedef struct s_chunk {
    struct s_chunk *prev;
    struct s_chunk *next;
    bool isfree;
    void *address;
    size_t size;
} chunk_t;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif
