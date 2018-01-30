/*
** EPITECH PROJECT, 2017
** CPool_Day04_2017
** File description:
** Returns a number, sent to the function as a string
*/

#include "my.h"

static int ind_from_base(char const c, char const *base);
static int try_to_add(int value, int inc);
static int end_value(int is_neg, int value);

int end_value(int is_neg, int value)
{
	if (is_neg == 1 && value <= -2147483647)
		value *= 0;
	else if (is_neg == 1)
		value *= -1;
	if ((is_neg < 0 && value > 0) || (is_neg > 0 && value < 0))
		value = 0;
	return (value);
}

int try_to_add(int value, int inc)
{
	if (value <= -214748364 && inc > 8)
		return (0);
	else if (value < -214748364)
		return (0);
	else
		return (1);
}

int ind_from_base(char const c, char const *base)
{
	for (int i = 0; i < my_strlen(base); i++)
		if (c == base[i])
			return (i);
	return (-1);
}

int my_getnbr_base(char const *str, char const *base)
{
	int cpt = 0;
	int ans = 0;
	int is_neg = 1;
	short nb_mode = 0;
	int act_dig_ind;
	int b_len = my_strlen(base);

	for (;str[cpt] != '\0'; cpt++) {
		act_dig_ind = ind_from_base(str[cpt], base);
		if ((act_dig_ind == -1) &&
		((str[cpt] != '+' || str[cpt] != '-') && nb_mode))
			return (0);
		if (act_dig_ind != -1) {
			nb_mode = 1;
			ans = (try_to_add(ans, act_dig_ind)) ?
				ans * b_len - (act_dig_ind) : 0;
		}
		if (str[cpt] == '-' && nb_mode == 0)
			is_neg *= -1;
	}
	return (end_value(is_neg, ans));
}