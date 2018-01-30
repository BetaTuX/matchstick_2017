/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Returns 0, and prints the string with non printable characters
*/

#include "my.h"

static char is_char_printable(char c);
static int print_hexacode(char c);
static int print_octacode(char c);

char is_char_printable(char c)
{
	return ((c <= 31 || c >= 127) ? 0 : 1);
}

int print_hexacode(char c)
{
	int chr_off = 0;

	chr_off += my_putchar('\\');
	if (c < 16)
		chr_off += my_putchar('0');
	return (my_putunbr_base(c, "0123456789abcdef") + chr_off);
}

int print_octacode(char c)
{
	int chr_off = 0;

	chr_off += my_putchar('\\');
	if (c < 8)
		chr_off += my_putstr("00");
	else if (c < 16)
		chr_off += my_putchar('0');
	return (my_putunbr_base(c, "01234567") + chr_off);
}

int my_showstr(char const *str, int w_base)
{
	char *act_char;
	int chr_printed = 0;

	act_char = (char *)str;
	while (*act_char != '\0') {
		if (!is_char_printable(*act_char) && w_base == 1)
			chr_printed += print_hexacode(*act_char);
		else if (!is_char_printable(*act_char) && w_base == 0)
			chr_printed += print_octacode(*act_char);
		else
			chr_printed += my_putchar(*act_char);
		act_char++;
	}
	return (chr_printed);
}
