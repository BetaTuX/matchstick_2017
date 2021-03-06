/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** ai_utils fx
*/

#include "matchstick.h"

bool is_end_game(int *map, int map_size)
{
	int tot = 0;

	for (int i = 0; i < map_size; i++)
		if (1 < map[i])
			tot++;
	return (tot <= 1);
}

int count_move_left(int *map, int map_size)
{
	int tot = 0;

	for (int i = 0; i < map_size; i++)
		if (0 < map[i])
			tot++;
	return (tot);
}

int get_index_maxline(int *map, int map_size)
{
	int tot = 0;

	for (int i = 0; i < map_size; i++)
		if (tot < map[i])
			tot = i;
	return (tot);
}

int sum_nim(int *map, int map_size)
{
	int tot = 0;

	for (int i = 0; i < map_size; i++)
		tot = tot ^ map[i];
	return (tot);
}