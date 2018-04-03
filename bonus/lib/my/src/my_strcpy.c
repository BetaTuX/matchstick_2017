/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Copies string into another one
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	for (int i = 0; i < my_strlen(src); i++)
		dest[i] = src[i];
	dest[my_strlen(src)] = '\0';
	return (dest);
}
