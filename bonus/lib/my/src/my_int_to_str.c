/*
** EPITECH PROJECT, 2017
** My lib
** File description:
** int to str
*/

#include "my.h"

char *int_to_str(int nb)
{
	char *ans = my_strdup("");
	char tmp[2] = "";
	bool neg = (nb < 0);

	if (nb == 0)
		ans = my_strcat(ans, "0");
	nb = (nb < 0) ? -nb : nb;
	while (0 < nb) {
		tmp[0] = (nb % 10) + '0';
		ans = my_strcat(ans, tmp);
		nb /= 10;
	}
	if (neg)
		ans = my_strcat(ans, "-");
	ans = my_revstr(ans);
	return (ans);
}