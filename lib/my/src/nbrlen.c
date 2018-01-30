/*
** EPITECH PROJECT, 2017
** My lib
** File description:
** Returns number length
*/

#include "my.h"

int unbrlen(unsigned int nb, unsigned char base)
{
	int i = 1;

	for (; base <= nb; i++)
		nb /= base;
	return (i);
}

int nbrlen(int nb)
{
	int i = 1;

	if (nb < 0) {
		i++;
		nb *= -1;
	}
	for (; 10 <= nb; i++)
		nb /= 10;
	return (i);
}