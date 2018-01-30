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

	if (nb <= 0)
		ans = my_strcat(ans, "0");
	while (0 < nb) {
		tmp[0] = (nb % 10) + '0';
		ans = my_strcat(ans, tmp);
		nb /= 10;
	}
	ans = my_revstr(ans);
	return (ans);
}