/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Puts every characters of every word in uppercase
*/

#include "my.h"

static void charupcase(char *c);
static void charlowcase(char *c);
static char is_char_a_word(char c);

void charupcase(char *c)
{
	*c = ('a' <= *c && *c <= 'z') ? *c - ('a' - 'A') : *c;
}

void charlowcase(char *c)
{
	*c = ('A' <= *c && *c <= 'Z') ? *c + ('a' - 'A') : *c;
}

char is_char_a_word(char c)
{
	return ((('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') ||\
('0' <= c && c <= '9')) ? 1 : 0);
}

char *my_strcapitalize(char *str)
{
	char n_word = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (is_char_a_word(str[i]) == 1 && n_word == 0) {
			charupcase(&str[i]);
			n_word = 1;
		}
		else if (!is_char_a_word(str[i]) && n_word == 1)
			n_word = 0;
		else
			charlowcase(&str[i]);
	return (str);
}