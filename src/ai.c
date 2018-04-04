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

static void process_selection(int *map, int line_nb, int max_taken, \
vector2i_t *vec)
{
	for (int i = line_nb - 1; 0 <= i; i--) {
		for (int j = my_even(max_taken); 0 < j; j -= 2) {
			if (j <= map[i]) {
				*vec = (vector2i_t){i, j};
				return;
			}
		}
	}
	for (int i = line_nb - 1; 0 <= i; i--) {
		if (0 < map[i]) {
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