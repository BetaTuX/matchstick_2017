/*
** EPITECH PROJECT, 2017
** CPool_Day08_2017
** File description:
** Splits a string into words.
*/

#include <stdlib.h>
#include "my.h"

static int is_alphanum(char c);
static int count_word_nb(char const *str);
static char *next_word(char const *str, int *ind);

int is_alphanum(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	else if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int count_word_nb(char const *str)
{
	int w_flag = 0;
	int ans = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (is_alphanum(str[i]) && w_flag == 0) {
			w_flag = 1;
			ans++;
		}
		else if (!is_alphanum(str[i]) && w_flag)
			w_flag = 0;
	return (ans);
}

char *next_word(char const *str, int *ind)
{
	int beg_ind;
	char *to_return;

	for (; !is_alphanum(str[*ind]) && str[*ind] != '\0'; *ind += 1);
	beg_ind = *ind;
	if (is_alphanum(str[*ind])) {
		for (; is_alphanum(str[*ind]); *ind += 1);
		to_return = malloc((*ind - beg_ind) * sizeof(char));
	} else if (beg_ind == *ind)
		return (0);
	for (int i = 0; i < *ind - beg_ind; i++)
		to_return[i] = str[beg_ind + i];
	return (my_strcat(my_strdup(to_return), "\0"));
}

char **my_str_to_word_array(char const *str)
{
	int ind = 0;
	int word_nb = count_word_nb(str);
	char **arr = malloc((word_nb + 1) * sizeof(char *));

	for (int i = 0; i < word_nb; i++) {
		arr[i] = next_word(str, &ind);
	}
	return (arr);
}