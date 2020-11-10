/*
** EPITECH PROJECT, 2020
** free
** File description:
** utils
*/

#include "libmy_malloc.h"

chunk_t	*destroy_last(chunk_t *tmp, chunk_t *ptr)
{
    if (tmp->prev == NULL)
        ptr = NULL;
    else
        tmp->prev->next = NULL;
    sbrk((tmp->size + sizeof(chunk_t)) * -1);
    return (ptr);
}

chunk_t *destroy_chunk(chunk_t *to_free)
{
    chunk_t	*old = to_free;

    to_free->isfree = true;
    for (to_free = to_free; to_free->prev != NULL &&
        to_free->prev->isfree != false;
        to_free = to_free->prev) {
        to_free->prev->size += to_free->size + sizeof(chunk_t);
        to_free->prev->next = to_free->next;
        to_free->next->prev = (to_free->next != NULL) ? to_free->prev :
        to_free->next->prev;
    }
    for (to_free->next = to_free->next; to_free->next != NULL &&
        to_free->next->isfree != false; to_free->next = to_free->next->next) {
        to_free->size += to_free->next->size + sizeof(chunk_t);
        to_free->next->next->prev = to_free;
    }
    old = (to_free->next == NULL) ? destroy_last(to_free, old) : old;
    return (old);
}