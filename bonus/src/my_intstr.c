/*
** EPITECH PROJECT, 2018
** My_Intstr
** File description:
** Function that convert an int to an str
*/

#include <stdlib.h>
#include "my.h"
#include "graph_matchstick.h"

char *my_intstr(int nbr)
{
	char *number = malloc(sizeof(*number) * 16);
	int i = 0;

	if (number == NULL)
		return (NULL);
	if (nbr == 0) {
		number[0] = '0';
		number[1] = '\0';
	}
	(nbr < 0) ? nbr = nbr * -1 : nbr;
	for (; nbr != 0; i++) {
		number[i] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	(nbr < 0) ? number[i += 1] = '-' : 0;
	number[i] = '\0';
	return (my_revstr(number));
}