/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** environnement checking fx
*/

#include <stdlib.h>
#include "my.h"
#include "graph_matchstick.h"

int get_env_var_ind(char **env, char *identifier)
{
	int separator_ind = 0;
	char *tmp = NULL;

	for (int i = 0; identifier && env[i]; i++) {
		separator_ind = my_strlim(env[i], '=');
		tmp = my_strpick(env[i], 0, separator_ind);
		if (!my_strcmp(tmp, identifier)) {
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (-1);
}