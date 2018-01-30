/*
** EPITECH PROJECT, 2017
** Matchstick
** File description:
** ai controller
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static bool valid_remove(int *map, int line_sel, int match_nb)
{
	if (line_sel != -1 && 0 < match_nb && match_nb <= map[line_sel])
		return (true);
	return (false);
}

void ai_turn(int *map, int line, int max_taken)
{
	int line_sel = -1;
	int match_nb = -1;

	my_putstr("AI's turn...\n");
	while (!valid_remove(map, line_sel, match_nb)) {
		line_sel = ABS(random()) % line;
		match_nb = ABS(random() % max_taken) + 1;
	}
	my_printf("AI removed %d match(es) from line %d\n", match_nb, \
line_sel + 1);
	map[line_sel] -= match_nb;
	return;
}