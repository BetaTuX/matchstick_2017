/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** header
*/

#ifndef MATCHSTICK_H_
	#define MATCHSTICK_H_

	#include <stdbool.h>

	typedef struct {
		int x;
		int y;
	} vector2i_t;

	void display_map(int *map, int size);
	int player_turn(int *map, int line, int max_taken);
	void ai_turn(int *map, int line, int max_taken);
	void process_selection(int *map, int line_nb, int max_taken, \
vector2i_t *vec);
	bool is_end_game(int *map, int map_size);
	int count_move_left(int *map, int map_size);
	int get_index_maxline(int *map, int map_size);
	int sum_nim(int *map, int map_size);
	int calculate_last_move(int max_stick, int moves_left, int max_taken);

	static inline int my_even(int nb)
	{
		return (nb - (nb % 2));
	}

	static inline int my_min(int v1, int v2)
	{
		if (v1 < v2)
			return (v1);
		else
			return (v2);
	}
#endif