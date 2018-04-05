/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** ai calculation
*/

#include "matchstick.h"

int calculate_last_move(int max_stick, int moves_left, int max_taken)
{
	int result = ((max_stick - (moves_left % 2)) % (max_taken + 1));

	if (0 < result)
		return (result);
	else
		return (1);
}

int calculate_move(int stick_nb, int nim_sum, int max_taken)
{
	int result = ((stick_nb - (stick_nb ^ nim_sum)) % (max_taken + 1));

	if (0 < result)
		return (result);
	else
		return (1);
}