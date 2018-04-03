/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Copies the n characters of a src string
*/

#include "my.h"
#include "stdlib.h"

char *my_strpick(char const *src, int start, int end)
{
	char *ans = malloc((end - start + 1) * sizeof(char));

	for (int i = 0; i < my_strlen(src) - start && i < end - start; i++)
		ans[i] = src[i + start];
	if (end > my_strlen(src))
		ans[my_strlen(src) - start] = '\0';
	else
		ans[end - start] = '\0';
	return (ans);
}
