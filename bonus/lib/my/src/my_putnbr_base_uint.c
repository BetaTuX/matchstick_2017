/*
** EPITECH PROJECT, 2017
** CPool_Day06_2017
** File description:
** Displays a number in a given base
*/

#include "my.h"

int my_putunbr_base(unsigned int nb, char const *base)
{
	int tmp;
	int base_s = my_strlen(base);
	int chr_nb = 1;

	tmp = nb % base_s;
	if (nb / base_s > 0) {
		chr_nb += my_putunbr_base(nb / base_s, base);
	}
	my_putchar(base[tmp]);
	return (chr_nb);
}
