/*
** EPITECH PROJECT, 2017
** Matchstick
** File description:
** ai controller
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "matchstick.h"

void process_selection(int *map, int line_nb, int max_taken, \
vector2i_t *vec)
{
	int nim = 0;

	for (int i = line_nb - 1; 0 <= i; i--)
		nim = nim ^ map[i];
	if (nim == 0 || max_taken < nim)
		nim = 1;
	for (int i = line_nb - 1; 0 <= i; i--) {
		if (nim <= map[i]) {
			*vec = (vector2i_t){i, 1};
			return;
		}
	}
}

void ai_turn(int *map, int line, int max_taken)
{
	vector2i_t vec = {-1, -1};

	my_putstr("AI's turn...\n");
	process_selection(map, line, max_taken, &vec);
	my_printf("AI removed %d match(es) from line %d\n", vec.y, \
vec.x + 1);
	map[vec.x] -= vec.y;
	return;
}