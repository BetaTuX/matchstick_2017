/*
** EPITECH PROJECT, 2017
** puterr
** File description:
** Prints a string in the error output
*/

#include "my.h"
#include <unistd.h>

int my_puterr(const char *s)
{
	write(2, s, my_strlen(s));
	return (my_strlen(s));
}
