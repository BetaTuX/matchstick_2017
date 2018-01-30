/*
** EPITECH PROJECT, 2017
** CPool_Day07_2017
** File description:
** Concatenates 2 strings
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int new_len = my_strlen(dest) + my_strlen(src) + 1;
	char *ans = malloc(new_len * sizeof(*ans));
	int i = 0;

	for (; dest[i] != 0; i++)
		ans[i] = dest[i];
	for (int j = 0; src[j] != 0; j++)
		ans[i + j] = src[j];
	ans[new_len - 1] = '\0';
	free(dest);
	dest = ans;
	return (dest);
}
