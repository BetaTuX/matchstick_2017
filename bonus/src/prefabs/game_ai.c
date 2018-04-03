/*
** EPITECH PROJECT, 2018
** graphical matchstick
** File description:
** game_gm_validatemove
*/

#include <stdlib.h>
#include <time.h>
#include "graph_matchstick.h"

DICT_RET(fetch_bool, bool);

static int select_stick(actor_t *stick)
{
	bool *selected = fetch_bool(stick->custom_var, "selected");

	if (HAS_FAILED(selected))
		return (0);
	*selected = true;
	return (1);
}

int gm_ai(scene_t *parent_scene)
{
	int stick_nb = my_list_size(parent_scene->actors) - 1;
	int stick_rem = ((rand() % 2) % (stick_nb - 1)) + 1;
	actor_t *act= NULL;
	linked_list_t *cur = parent_scene->actors;

	for (int i = 0; i < stick_rem;) {
		act = (actor_t *)cur->data;
		if (!my_strcmp(act->name, "stick"))
			i += select_stick(act);
		cur = cur->next;
	}
	my_delete_nodes(&(parent_scene->actors), NULL, &stick_selected);
	return (0);
}