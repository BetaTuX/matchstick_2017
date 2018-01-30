/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** header
*/

#ifndef MATCHSTICK_H_
	#define MATCHSTICK_H_

	void display_map(int *map, int size);
	int player_turn(int *map, int line, int max_taken);
	int ai_turn(int *map, int line, int max_taken);

#endif /* !MATCHSTICK_H_ */
