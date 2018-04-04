/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the create_blank_champion function
*/

/* File created the 13/02/2018 at 17:01:18 by julian.frabel@epitech.eu */

#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "matchstick.h"

Test(ai_process, full_map, .timeout=10)
{
	vector2i_t vec = {-1, -1};
	vector2i_t exp = {3, 1};
	int map_size = 3;
	int map[3] = {1, 2, 3};
	int max_taken = 3;

	process_selection(map, map_size, max_taken, &vec);
	cr_assert_eq(vec.x, exp.x - 1);
	cr_assert_eq(vec.y, exp.y);
}

Test(ai_process, one_possibility, .timeout=10)
{
	vector2i_t vec = {-1, -1};
	vector2i_t exp = {1, 1};
	int map_size = 3;
	int map[3] = {1, 0, 0};
	int max_taken = 3;

	process_selection(map, map_size, max_taken, &vec);
	cr_assert_eq(vec.x, exp.x - 1);
	cr_assert_eq(vec.y, exp.y);
}

Test(ai_process, mid_game, .timeout=10)
{
	vector2i_t vec = {-1, -1};
	vector2i_t exp = {1, 1};
	int map_size = 3;
	int map[3] = {1, 0, 0};
	int max_taken = 3;

	process_selection(map, map_size, max_taken, &vec);
	cr_assert_eq(vec.x, exp.x - 1);
	cr_assert_eq(vec.y, exp.y);
}