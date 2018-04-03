/*
** EPITECH PROJECT, 2017
** printf lib
** File description:
** some printf functions
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

int pf_u(va_list vl, char *flags)
{
	unsigned int i = va_arg(vl, unsigned int);
	int chr_off = 0;

	free(flags);
	return (my_putunbr_base(i, "0123456789") + chr_off);
}

int pf_p(va_list vl, char *flags)
{
	void *i = va_arg(vl, void *);
	int chr_off = 0;

	my_putstr("0x");
	chr_off += 2;
	free(flags);
	return (my_putunbr_base((unsigned long)i,\
"0123456789abcdef") + chr_off);
}