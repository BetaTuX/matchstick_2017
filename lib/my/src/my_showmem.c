/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Prints a memory dump and return 0
*/

#include "my.h"

static void print_addr(char const *c);
static void print_hex(char const *c, int *size);
static void print_content(char const *c, int *size);
static char is_memchar_printable(char c);

void print_addr(char const *c)
{
	int z_to_disp = 0;

	for (int k = *(int *)c; k > 0; k /= 16)
		z_to_disp++;
	for (z_to_disp = 8 - z_to_disp; z_to_disp > 0; z_to_disp -= 1)
		my_putchar('0');
	my_putnbr_base(*(int *)c, "0123456789ABCDEF");
	my_putstr(":  ");
}

void print_hex(char const *c, int *size)
{
	for (int i = 0; i < 16; i++) {
		if (i % 2 == 0 && i != 0)
			my_putchar(' ');
		if (c[i] > 16 && i < *size)
			my_putnbr_base(c[i], "0123456789ABCDEF");
		else if (i < *size) {
			my_putchar('0');
			my_putnbr_base(c[i], "0123456789ABCDEF");
		}
		if (i >= *size)
			my_putstr("  ");
		*size -= 1;
	}
}

void print_content(char const *c, int *size)
{
	my_putchar(' ');
	for (int i = 0; i < 16 && i < *size; i++)
		if (is_memchar_printable(c[i]))
			my_putchar(c[i]);
		else if (!is_memchar_printable(c[i]))
			my_putchar('.');
		else
			my_putchar(' ');
}

char is_memchar_printable(char c)
{
	return ((c <= 31 || c >= 127) ? 0 : 1);
}

int my_showmem(char const *str, int size)
{
	int t_size = size;

	for (int i = 0; i < size - 16; i += 16) {
		print_addr(&str[i]);
		print_hex(&str[i], &t_size);
		print_content(&str[i], &t_size);
		my_putchar('\n');
	}
	return (0);
}
