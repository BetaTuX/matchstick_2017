/*
** EPITECH PROJECT, 2017
** CPool_Day05_2017
** File description:
** Returns the square root of the number given as an argument
*/

#include "my.h"

int my_square_root(int nb)
{
	int ans = 0;

	while (ans * ans < nb)
		ans++;
	return ((ans * ans == nb) ? ans : 0);
}
