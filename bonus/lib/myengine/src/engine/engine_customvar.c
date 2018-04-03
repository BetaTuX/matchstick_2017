/*
** EPITECH PROJECT, 2018
** Runner 2017
** File description:
** custom var support
*/

#include <stdlib.h>
#include "engine.h"

void add_var(linked_dict_t **list, char *id, void *data)
{
	void **var = malloc(2 * sizeof(void *));

	var[0] = my_strdup(id);
	var[1] = data;
	push(list, var);
}

void *fetch_var(linked_dict_t *list, const char *id)
{
	linked_dict_t *cur = list;

	for (; cur != 0; cur = cur->next) {
		if (!my_strcmp(((void **)(cur->data))[0], id))
			return (((void **)(cur->data))[1]);
	}
	return ((void *)- 1);
}

void destroy_varlist(linked_dict_t *var_list)
{
	linked_dict_t *cur = var_list;

	while (var_list != 0) {
		cur = var_list;
		var_list = var_list->next;
		free(((void **)(cur->data))[0]);
		free(cur->data);
		free(cur);
	}
}