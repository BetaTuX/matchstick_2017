/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Copies the n characters of a src string
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
	for (int i = 0; i < my_strlen(src) && i < n; i++)
		dest[i] = src[i];
	if (n > my_strlen(src))
		dest[my_strlen(src)] = '\0';
	else
		dest[n] = '\0';
	return (dest);
}
