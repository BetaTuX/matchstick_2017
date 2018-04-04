/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** player controller
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "matchstick.h"
#include "global.h"

static int get_line_ind(int line)
{
	AUTO_FREE char *str = NULL;
	int nb = 0;

	while (1) {
		my_putstr("Line: ");
		free(str);
		str = get_next_line(0);
		if (!str)
			break;
		nb = my_getnbr(str);
		if (!my_str_isnum(str))
			my_putstr(ERR_INV_INP);
		else if (0 < nb && nb <= line)
			return (nb - 1);
		else
			my_putstr(ERR_LINE_OOR);
	}
	return (-1);
}

static int check_input(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (!('0' <= str[i] && str[i] <= '9')) {
			my_putstr(ERR_INV_INP);
			return (1);
		}
	}
	return (0);
}

static int get_match_taken(int line_content, int max_taken)
{
	AUTO_FREE char *str = NULL;
	int nb = 0;

	my_putstr("Matches: ");
	free(str);
	str = get_next_line(0);
	if (!str)
		return (-2);
	if (check_input(str))
		return (-1);
	nb = my_getnbr(str);
	if (nb <= 0) {
		my_putstr(ERR_NE_MATCHES);
		return (-1);
	} else if (max_taken < nb || line_content < nb) {
		my_putstr(ERR_TM_MATCHES);
		return (-1);
	}
	return (nb);
}

int player_turn(int *map, int line, int max_taken)
{
	int line_ind = 0;
	int matches_taken = 0;

	my_putstr("Your turn:\n");
	while (1) {
		line_ind = get_line_ind(line);
		if (line_ind < 0)
			return (line_ind);
		matches_taken = get_match_taken(map[line_ind], max_taken);
		if (0 <= matches_taken)
			break;
		else if (matches_taken == -2)
			return (-1);
	}
	map[line_ind] -= matches_taken;
	my_printf("Player removed %d match(es) from line %d\n", matches_taken, \
line_ind + 1);
	return (0);
}