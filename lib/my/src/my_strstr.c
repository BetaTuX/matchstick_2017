/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Reproduce the behavior of strstr
*/

#include "my.h"

static char *is_str_in_str_from_ind(char const *str, char const *to_find,\
int ind);

char *is_str_in_str_from_ind(char const *str, char const *to_find, int ind)
{
	int c_match = 0;

	for (int i = 0; i < my_strlen(to_find) && \
(ind + i) < my_strlen(str); i++) {
		if (str[ind + i] == to_find[i])
			c_match++;
		else
			return (0);
	}
	return ((char *)&str[ind]);
}

char *my_strstr(char const *str, char const *to_find)
{
	int src_str_len = my_strlen(str);
	char *ans = 0;

	for (int i = 0; i < src_str_len;i++) {
		ans = is_str_in_str_from_ind(str, to_find, i);
		if (ans != 0)
			i = src_str_len;
	}
	return (ans);
}

char *my_strstr_l(char const *str, char const *to_find, int ind_to_begin)
{
	char *ans = 0;

	for (int i = ind_to_begin; 0 <= i; i--) {
		ans = is_str_in_str_from_ind(str, to_find, i);
		if (ans != 0)
			break;
	}
	if (ans == 0)
		return ((char *)str);
	else
		return (ans + 1);
}