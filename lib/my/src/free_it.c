/*
** EPITECH PROJECT, 2017
** my lib
** File description:
** auto free fx
*/

#include <stdlib.h>

void free_it(void *ptr)
{
	void **to_free = ptr;

	free(*to_free);
}