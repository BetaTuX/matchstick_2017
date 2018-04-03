/*
** EPITECH PROJECT, 2018
** lib my 2017
** File description:
** nbr to str
*/

#include <stdlib.h>
#include "my.h"

static int digits_count(int nb)
{
	int i = 0;

	if (nb < 0) {
		i++;
		nb *= -1;
	}
	for (; nb > 0; i++)
		nb = nb / 10;
	return (i);
}

static int process_nbrstr(char *str, int nb)
{
	int ind = 0;
	char tmp = 0;

	if (nb < 0) {
		str[0] = '-';
		ind++;
	}
	tmp = nb % 10;
	if (nb / 10 > 0)
		ind += process_nbrstr(str, nb / 10);
	tmp += '0';
	str[ind] = tmp;
	return (ind);
}

char *my_nbrstr(int nb)
{
	char *ans = malloc((digits_count(nb) + 1) * sizeof(*ans));

	if (ans == (void *)0)
		return (ans);
	process_nbrstr(ans, nb);
	return (ans);
}