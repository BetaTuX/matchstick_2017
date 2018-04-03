/*
** EPITECH PROJECT, 2018
** My Float To Str
** File description:
** Function that convert a float to a string
*/

#include <stdlib.h>
#include "my.h"
#include "graph_matchstick.h"

static int my_strlen_int(int nbr)
{
	int count = 0;

	for (; nbr != 0; count++)
		nbr = nbr / 10;
	return (count);
}

char *my_float_to_str(float nbr)
{
	int int_part = (int)nbr;
	float float_part = nbr - (float)int_part;
	char *result = malloc(sizeof(*result) * 16);
	AUTO_FREE char *second_part = malloc(sizeof(*second_part) * 16);
	int size_of_nbr = my_strlen_int(int_part);

	if (nbr == 0) {
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result = my_intstr(int_part);
	result[size_of_nbr] = '.';
	result[size_of_nbr + 1] = '\0';
	float_part = float_part * (10 * 10);
	second_part = my_intstr((int)float_part);
	second_part[my_strlen(second_part)] = '\0';
	result = my_strcat(result, second_part);
	return (result);
}