/*
** EPITECH PROJECT, 2017
** CPool_Day08_2017
** File description:
** Returns the result from the nbr string conversion
*/

#include <stdlib.h>
#include "my.h"

static char *number_in_new_base(char *ans, int nbr, char const *base, int ind);

char *number_in_new_base(char *ans, int nbr, char const *base, int ind)
{
	int base_len = my_strlen(base);
	int was_neg = 0;

	if (nbr < 0) {
		nbr *= -1;
		was_neg = 1;
		ind ++;
	}
	for (; 0 < ind; ind -= 1) {
		ans[ind - 1] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (was_neg)
		ans[0] = '-';
	return (ans);
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
	int base_f_len = my_strlen(base_to);
	int nbr_f = my_getnbr_base(nbr, base_from);
	int dig_nb_end = 1;
	char *ans;

	for (int i = nbr_f; base_f_len < i || i < - base_f_len; i /= base_f_len)
		dig_nb_end++;
	if (nbr_f < 0)
		ans = malloc((dig_nb_end + 2) * sizeof(char));
	else
		ans = malloc((dig_nb_end + 1) * sizeof(char));
	ans = number_in_new_base(ans, nbr_f, base_to, dig_nb_end);
	return (ans);
}