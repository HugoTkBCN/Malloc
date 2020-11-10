/*
** EPITECH PROJECT, 2020
** free
** File description:
** .c
*/

#include "libmy_malloc.h"
#include "utils.h"

extern chunk_t *tampon;

void free(void *ptr)
{
    chunk_t	*tmp = NULL;

    if (ptr == NULL)
        return ;
    for (tmp = tampon; tmp != NULL; tmp = tmp->next) {
        if (tmp->address == ptr) {
            tampon = destroy_chunk(tmp) == NULL ? NULL : tampon;
            break;
        }
    }
}