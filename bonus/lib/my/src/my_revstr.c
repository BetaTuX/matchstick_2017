/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Reverses a string passed in parameter
*/

#include "my.h"

char *my_revstr(char *str)
{
	int str_len = 0;
	int cpt = 0;

	while (str[str_len] != '\0')
		str_len++;
	str_len -= 1;
	while (cpt < (str_len + 1) / 2) {
		str[str_len - cpt] += str[cpt];
		str[cpt] = str[str_len - cpt] - str[cpt];
		str[str_len - cpt] -= str[cpt];
		cpt++;
	}
	return (str);
}
