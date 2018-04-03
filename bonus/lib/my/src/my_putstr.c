/*
** EPITECH PROJECT, 2017
** CPool_Day04_2017
** File description:
** Displays, one-by-one, the characters of a string
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
	return (write(1, str, my_strlen(str)));
}
