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

int pf_id(va_list vl, char *flags)
{
	int i = va_arg(vl, int);
	int flag_ans = 0;

	flag_ans = offset_iflag(i, flags);
	free(flags);
	return (flag_ans);
}

int pf_b(va_list vl, char *flags)
{
	unsigned int i = va_arg(vl, unsigned int);
	int chr_off = 0;

	if (my_strstr(flags, "#") != 0) {
		my_putstr("0b");
		chr_off += 2;
	}
	free(flags);
	return (my_putunbr_base(i, "01") + chr_off);
}

int pf_x(va_list vl, char *flags)
{
	unsigned int i = va_arg(vl, unsigned int);
	int chr_off = 0;

	if (my_strstr(flags, "#") != 0) {
		my_putstr("0x");
		chr_off += 2;
	}
	free(flags);
	return (my_putunbr_base(i, "0123456789abcdef") + chr_off);
}

int pf_x_up(va_list vl, char *flags)
{
	unsigned int i = va_arg(vl, unsigned int);
	int chr_off = 0;

	if (my_strstr(flags, "#") != 0) {
		my_putstr("0X");
		chr_off += 2;
	}
	free(flags);
	return (my_putunbr_base(i, "0123456789ABCDEF") + chr_off);
}

int pf_o(va_list vl, char *flags)
{
	unsigned int i = va_arg(vl, unsigned int);
	int flag_ans = 0;

	flag_ans = offset_oflag(i, flags);
	free(flags);
	return (flag_ans);
}