/*
** EPITECH PROJECT, 2017
** CPool_Day05_2017
** File description:
** Returns the first argument raised to the second argument
*/

#include "my.h"

int my_power(int nb, int p)
{
	if (p <= 0)
		return ((p == 0) ? 1 : 0);
	return (nb * (my_power(nb, p - 1)));
}