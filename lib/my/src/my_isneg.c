/*
** EPITECH PROJECT, 2017
** CPool_Day03_2017
** File description:
** Displays N if number is negative, P if positive or null
*/

#include "my.h"

int my_isneg(int n)
{
	if (n < 0) {
		my_putchar(78);
	} else {
		my_putchar(80);
	}
	return (0);
}
