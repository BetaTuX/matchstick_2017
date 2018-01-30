/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Returns 1 if string contains only printable characters, returns 0 otherwise
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] <= 31 || str[i] == 127)
			return (0);
	return (1);
}
