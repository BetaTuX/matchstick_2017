/*
** EPITECH PROJECT, 2018
** matshcaz
** File description:
** count stick in game
*/

#include "graph_matchstick.h"

int count_actor_named(scene_t *scn, char *name)
{
	int tot = 0;
	actor_t *act = NULL;

	for (linked_list_t *cur = scn->actors; cur; cur = cur->next) {
		act = (actor_t *)cur->data;
		if (!my_strcmp(act->name, name))
			tot++;
	}
	return (tot);
}

int count_selected_stick(scene_t *scn)
{
	int tot = 0;
	actor_t *act = NULL;

	for (linked_list_t *cur = scn->actors; cur; cur = cur->next) {
		act = (actor_t *)cur->data;
		if (!my_strcmp(act->name, "stick"))
			tot += !stick_selected(NULL, act);
	}
	return (tot);
}