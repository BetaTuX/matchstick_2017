/*
** EPITECH PROJECT, 2017
** CPool_Day04_2017
** File description:
** Swaps content of two integers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
