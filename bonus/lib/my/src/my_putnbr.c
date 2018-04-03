/*
** EPITECH PROJECT, 2017
** CPool_Day03_2017
** File description:
** Displays a number, digits by digits
*/

#include "my.h"

static int is_neg(int nb);

int is_neg(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		if (nb == -2147483648) {
			my_putchar('2');
			nb = 147483648;
			return (nb);
		}
		nb *= -1;
	}
	return (nb);
}

int my_putnbr(int nb)
{
	int tmp;
	int chr_nb = 1;

	nb = is_neg(nb);
	tmp = nb % 10;
	if (nb / 10 > 0)
		chr_nb += my_putnbr(nb / 10);
	tmp += '0';
	my_putchar(tmp);
	return (chr_nb);
}
