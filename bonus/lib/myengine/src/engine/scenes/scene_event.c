/*
** EPITECH PROJECT, 2018
** my engine
** File description:
** scene event
*/

#include "engine.h"

void scene_event(scene_t *self, sfEvent *evt)
{
	linked_list_t *cur = self->actors;

	actor_t *actor = NULL;
	if (evt->type == sfEvtKeyReleased && evt->key.code == sfKeyEscape && \
self->pauseable)
		self->gamemode->paused = !(self->gamemode->paused);
	for (; cur && !(self->gamemode->paused); cur = cur->next) {
		actor = (actor_t *)(cur->data);
		if (actor->event)
			actor->event(actor, evt);
	}
	if (self->gamemode->paused)
		self->ui->event(self, evt);
}