/*
** EPITECH PROJECT, 2017
** CPool_Day04_2017
** File description:
** Returns a number, sent to the function as a string
*/

#include "my.h"

int my_getnbr(char const *str)
{
	return (my_getnbr_base(str, "0123456789"));
}