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
	int index_maxline = get_index_maxline(map, line_nb);
	int moves_left = count_move_left(map, line_nb);
	int nim_sum = sum_nim(map, line_nb);

	*vec = (vector2i_t){index_maxline, 1};
	if (is_end_game(map, line_nb)) {
		if (!(map[index_maxline] == 1 && (moves_left % 2) == 1))
			vec->y = ((map[index_maxline] - (moves_left % 2)) \
% (max_taken + 1));
		return;
	}
	if (nim_sum == 0)
		return;
	for (int i = 0; i < line_nb; i++)
		if ((map[i] ^ nim_sum) < map[i]) {
			*vec = (vector2i_t){i, ((map[i] - (map[i] ^ nim_sum)) %\
(max_taken + 1))};
			return;
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