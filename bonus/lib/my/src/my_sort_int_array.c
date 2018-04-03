/*
** EPITECH PROJECT, 2017
** CPool_Day04_2017
** File description:
** Sorts integerarray in ascending order
*/

#include "my.h"

static void compare_and_sort(int *array, int index);

void compare_and_sort(int *array, int index)
{
	if (array[index] < array[index - 1]) {
		array[index] += array[index - 1];
		array[index - 1] = array[index] - array[index - 1];
		array[index] = array[index] - array[index - 1];
	}
}

void my_sort_int_array(int *array, int size)
{
	for (int i = 1; i < size; i++) {
		for (int j = size; i < j; j -= 1) {
			compare_and_sort(array, j - 1);
		}
	}
}