/*
** EPITECH PROJECT, 2020
** alloc
** File description:
** utils
*/

#include "libmy_malloc.h"

chunk_t *get_chunk(chunk_t *this, void *ptr)
{
    if (ptr == NULL)
        return (NULL);
    for (this = this; this != NULL; this = this->next)
        if (this->address == ptr)
            return (this);
    return (NULL);
}

chunk_t *get_free_chunk(size_t const size, chunk_t *this)
{
    if (this == NULL)
        return (NULL);
    for (this = this; this->next != NULL; this = this->next)
        if (this->isfree == true && size <= this->size)
            return (this);
    return (NULL);
}

void *create_chunk(size_t const size, chunk_t *new)
{
    void *address = sbrk(size + sizeof(chunk_t));

    if (address == (void *) - 1)
        return (NULL);
    for (new = new; new->next != NULL; new = new->next);
    new->next = address;
    new->next->address = address + sizeof(chunk_t);
    new->next->isfree = false;
    new->next->prev = new;
    new->next->next = NULL;
    new->next->size = size;
    return (new->next);
}

void *init_memory(size_t const size)
{
    chunk_t	*new_memory_map = NULL;
    void *address = NULL;

    if ((address = sbrk(size + sizeof(chunk_t))) == (void *)-1)
        return (NULL);
    new_memory_map = (void *)address;
    new_memory_map->isfree = false;
    new_memory_map->prev = NULL;
    new_memory_map->next = NULL;
    new_memory_map->size = size;
    new_memory_map->address = address + sizeof(chunk_t);
    return (new_memory_map);
}