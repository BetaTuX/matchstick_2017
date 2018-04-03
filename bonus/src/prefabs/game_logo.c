/*
** EPITECH PROJECT, 2018
** matchstick graphical bonus
** File description:
** stick actor object
*/

#include <stdlib.h>
#include "graph_matchstick.h"

static void logo_event(actor_t *self, sfEvent *evt)
{
	scene_t *scn = fetch_var(self->custom_var, "parent_scene");
	int (*fx)(scene_t *) = NULL;

	if (HAS_FAILED(scn))
		return;
	if (evt->type != sfEvtKeyReleased)
		return;
	fx = fetch_var(scn->gamemode->var, "play_validate");
	if (HAS_FAILED(fx))
		return;
	if (evt->key.code == sfKeySpace)
		fx(scn);
}

void logo_init(actor_t *actor)
{
	actor->rect = (sfIntRect){0, 0, 0, 0};
	actor->event = &logo_event;
}