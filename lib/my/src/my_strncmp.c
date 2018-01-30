/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Reproduces the behavior of strncmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int ind;

	n *= (n < 0) ? -1 : 1;
	for (ind = 0; s1[ind] != '\0' && s2[ind] != '\0' && ind < n; ind++)
		if (s1[ind] < s2[ind])
			return (s1[ind] - s2[ind]);
		else if (s1[ind] > s2[ind])
			return (s1[ind] - s2[ind]);
	if (my_strlen(s1) > my_strlen(s2))
		return (s1[ind]);
	else if (my_strlen(s2) > my_strlen(s1))
		return (- s2[ind]);
	return (0);
}
