/*
** EPITECH PROJECT, 2017
** matchsitck 2017
** File description:
** main
*/

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "my.h"
#include "matchstick.h"
#include "global.h"

static bool check_end(int *map, int size)
{
	for (int i = 0; i < size; i++)
		if (0 < map[i])
			return (false);
	return (true);
}

static int *create_map(int line)
{
	int *map = malloc((line) * sizeof(*map));
	int last = 1;

	if (!map)
		return (NULL);
	for (int i = 0; i < line; i++) {
		map[i] = last;
		last += 2;
	}
	return (map);
}

static int matchstick_loop(int *map, int line, int max_taken)
{
	while (1) {
		display_map(map, line);
		if (check_end(map, line)) {
			my_putstr(END_WIN_MSG);
			return (1);
		}
		if (player_turn(map, line, max_taken) == -1)
			break;
		display_map(map, line);
		if (check_end(map, line)) {
			my_putstr(END_LOSE_MSG);
			return (2);
		}
		ai_turn(map, line, max_taken);
	}
	return (0);
}

static int print_usage(void)
{
	my_putstr(USAGE);
	return (84);
}

int main(int argc, char **argv)
{
	AUTO_FREE int *map = NULL;
	int line = 0;
	int max_match = 0;

	srandom(time(NULL));
	if (argc < 3)
		return (print_usage());
	line = my_getnbr(argv[1]);
	max_match = my_getnbr(argv[2]);
	if (max_match <= 0 || line <= 0 || 100 <= line)
		return (print_usage());
	map = create_map(line);
	if (!map)
		return (84);
	return (matchstick_loop(map, line, my_getnbr(argv[2])));
}
