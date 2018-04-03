/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Returns 1 if the string only contains alphabetical characaters, O otherwise
*/

#include "my.h"

static char is_char_a_word_ia(char c);

char is_char_a_word_ia(char c)
{
	return ((('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) ? 1 : 0);
}

int my_str_isalpha(char const *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (is_char_a_word_ia(str[i]) == 0)
			return (0);
	return (1);
}
