/*
** EPITECH PROJECT, 2017
** bootstrap my_printf
** File description:
** same behavior as printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

int offset_sflag(char *str, char *flags)
{
	char *opt_str;
	int char_lim = 0;
	int i = 0;

	for (; i < my_getnbr(flags) - my_strlen(str); i++)
		char_lim += my_putchar(' ');
	if ((opt_str = my_strstr(flags, "."))) {
		opt_str = my_strpick(flags, my_getnbr(opt_str + 1),\
my_strlen(flags));
		char_lim = my_putstr(opt_str);
		free(opt_str);
	} else if ((opt_str = my_strstr(flags, "-"))) {
		char_lim += my_putstr(str);
		for (i = 0; i < my_getnbr(opt_str + 1) - my_strlen(str); i++)
			char_lim += my_putchar(' ');
	} else {
		char_lim += my_putstr(str);
	}
	return (char_lim);
}

int offset_iflag(int nbr, char *flags)
{
	char *opt_str;
	int char_off = 0;

	for (int i = 0; i < my_getnbr(flags) - nbrlen(nbr); i++)
		char_off += my_putchar(' ');
	if ((opt_str = my_strstr(flags, "-"))) {
		char_off += my_putnbr(nbr);
		opt_str = my_strpick(flags, my_getnbr(opt_str + 2),\
my_strlen(flags));
		for (int i = 0; i < my_getnbr(opt_str + 1) - nbrlen(nbr); i++)
			char_off += my_putchar(' ');
	} else {
		char_off += my_putnbr(nbr);
	}
	return (char_off);
}

int offset_oflag(unsigned int nbr, char *flags)
{
	char *opt_str;
	int char_off = 0;

	for (int i = 0; i < my_getnbr(flags) - unbrlen(nbr, 8); i++)
		char_off += my_putchar(' ');
	if ((opt_str = my_strstr(flags, "-"))) {
		if (my_strstr(flags, "#") != 0)
			char_off += my_putchar('0');
		char_off += my_putunbr_base(nbr, "01234567");
		opt_str = my_strpick(flags, my_getnbr(opt_str + 2),\
my_strlen(flags));
		for (int i = 0; i < my_getnbr(opt_str + 1) - unbrlen(nbr, 8);\
i++)
			char_off += my_putchar(' ');
	} else {
		if (my_strstr(flags, "#") != 0)
			char_off += my_putchar('0');
		char_off += my_putunbr_base(nbr, "01234567");
	}
	return (char_off);
}