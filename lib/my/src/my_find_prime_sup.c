/*
** EPITECH PROJECT, 2017
** CPool_Day05_2017
** File description:
** Returns the smallest prime number that is greater or equal than the parameter
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
	nb = (nb < 2) ? 2 : nb;
	while (my_is_prime(nb) == 0)
		nb++;
	return (nb);
}