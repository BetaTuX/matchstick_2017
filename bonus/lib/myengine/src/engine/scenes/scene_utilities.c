/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** scene basic fx
*/

#include "engine.h"

void scene_tick(scene_t *self, float dta)
{
	linked_list_t *cur = self->actors;
	actor_t *actor = NULL;

	for (; cur && !(self->gamemode->paused); cur = cur->next) {
		actor = (actor_t *)(cur->data);
		if (actor->tick)
			actor->tick(actor, dta);
	}
	if (self->gamemode && self->gamemode->tick)
		self->gamemode->tick(self->gamemode, dta);
}

void scene_render(scene_t *self, sfRenderWindow *wdw)
{
	linked_list_t *cur = self->actors;
	actor_t *actor = NULL;

	for (; cur; cur = cur->next) {
		actor = (actor_t *)(cur->data);
		if (actor->render)
			actor->render(actor, wdw);
	}
	if (self->ui && self->ui->draw)
		self->ui->draw(self, wdw);
}