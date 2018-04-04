/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** header
*/

#ifndef MATCHSTICK_H_
	#define MATCHSTICK_H_

	typedef struct {
		int x;
		int y;
	} vector2i_t;

	void display_map(int *map, int size);
	int player_turn(int *map, int line, int max_taken);
	void ai_turn(int *map, int line, int max_taken);

	static inline int my_even(int nb)
	{
		return (nb - (nb % 2));
	}
#endif