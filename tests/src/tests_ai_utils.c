/*
** EPITECH PROJECT, 2017
** CPE_corewar
** File description:
** Test the create_blank_champion function
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "matchstick.h"

Test(ai_utils, small_map_maxindex, .timeout=10)
{
	int map_size = 2;
	int map[2] = {1, 3};

	cr_assert_eq(get_index_maxline(map, map_size), 1);
	map[1] = 0;
	cr_assert_eq(get_index_maxline(map, map_size), 0);
}

Test(ai_utils, large_map_maxindex, .timeout=10)
{
	int map_size = 9;
	int map[9] = {1, 3, 5, 7, 9, 11, 13, 15, 17};

	cr_assert_eq(get_index_maxline(map, map_size), 8);
	for (int i = 4; i < map_size; i++)
		map[i] = 0;
	cr_assert_eq(get_index_maxline(map, map_size), 3);
	map[6] = 13;
	cr_assert_eq(get_index_maxline(map, map_size), 6);
}

Test(ai_utils, small_sum_nim, .timeout=10)
{
	int map_size = 3;
	int map[3] = {1, 3, 5};

	cr_assert_eq(sum_nim(map, map_size), 7);
	map[1] = 0;
	cr_assert_eq(sum_nim(map, map_size), 4);
	map[1] = 3;
	map[2] = 0;
	cr_assert_eq(sum_nim(map, map_size), 2);
	map[1] = 0;
	map[2] = 4;
	cr_assert_eq(sum_nim(map, map_size), 5);
}

Test(ai_utils, large_sum_nim, .timeout=10)
{
	int map_size = 5;
	int map[5] = {1, 0, 5, 7, 8};

	cr_assert_eq(sum_nim(map, map_size), 11);
}