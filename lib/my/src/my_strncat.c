/*
** EPITECH PROJECT, 2017
** CPool_Day07_2017
** File description:
** Concatenates 2 strings until the n characters
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
	for (int i = 0; i < n && i < my_strlen(src); i++)
		dest[my_strlen(dest)] = src[i];
	dest[my_strlen(dest) + my_strlen(src)] = '\0';
	return (dest);
}
