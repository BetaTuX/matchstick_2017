/*
** EPITECH PROJECT, 2018
** cook
** File description:
** recipe comparaison fx
*/

#include "graph_matchstick.h"

bool recipe_eq(char *recipe[3], char *ingredients[3])
{
	for (int i = 0; i < 3; i++) {
		if ((recipe[i] && !ingredients[i]) || \
(!recipe[i] && ingredients[i]))
			return (false);
		else if (recipe[i] == ingredients[i] || \
!my_strcmp(recipe[i], ingredients[i]))
			continue;
		else
			return (false);
	}
	return (true);
}