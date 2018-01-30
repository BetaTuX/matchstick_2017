/*
** EPITECH PROJECT, 2017
** CPool_Day04_2017
** File description:
** Returns the number of characters in the string passed in parameters
*/

#include "my.h"

int my_strlen(char const *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++);
	return (i);
}
