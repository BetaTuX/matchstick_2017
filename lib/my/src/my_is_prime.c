/*
** EPITECH PROJECT, 2017
** CPool_Day05_2017
** File description:
** Returns 1 if the number is prime, 0 if not
*/

#include "my.h"

int my_is_prime(int nb)
{
	for (int i = 2; i < nb; i++)
		if (nb % i == 0)
			return (0);
	return ((nb < 2) ? 0 : 1);
}
