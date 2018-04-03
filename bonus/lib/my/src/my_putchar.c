/*
** EPITECH PROJECT, 2017
** CPool_Day03_2017
** File description:
** print a character with an ASCII decimal code
*/

#include <unistd.h>
#include "my.h"

int my_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
