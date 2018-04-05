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
	int moves_left = count_move_left(map, line_nb);
	int index_maxline = get_index_maxline(map, line_nb);
	int nim_sum = 0;

	if (is_end_game(map, line_nb)) {
		if (map[index_maxline] == 1 && (moves_left % 2) == 1)
			*vec = (vector2i_t){index_maxline, 1};
		else
			*vec = (vector2i_t){index_maxline, (map[index_maxline] \
- (moves_left % 2)) % max_taken};
		return;
	}
	for (int i = 0; i < line_nb; i++)
		nim_sum = nim_sum ^ map[i];
	for (int i = 0; i < line_nb; i++)
		if ((map[i] ^ (nim_sum != 0) ? nim_sum : 1) < map[i]) {
			*vec = (vector2i_t){i, (map[i] - (map[i] ^ nim_sum)) % \
max_taken};
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