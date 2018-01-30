/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Returns 1 if the string only contains lowercase characters,
*/

#include "my.h"

int my_str_islower(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < 'a' || 'z' < str[i])
			return (0);
	return (1);
}
