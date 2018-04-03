/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Puts every characters of every word in uppercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] += ('A' <= str[i] && str[i] <= 'Z') ? 'a' - 'A' : 0;
	return (str);
}
