/*
** EPITECH PROJECT, 2018
** matchstick graphical bonus
** File description:
** stick actor object
*/

#include <stdlib.h>
#include "graph_matchstick.h"

static void stick_render(actor_t *self, sfRenderWindow *wdw)
{
	update_anim(self);
	actor_render(self, wdw);
}

static void stick_event(actor_t *self, sfEvent *evt)
{
	void *selected = fetch_var(self->custom_var, "selected");
	bool hover = false;
	bool clicked = evt->type == sfEvtMouseButtonPressed;

	if (clicked)
		hover = mouse_overlap(self, &(sfVector2i){evt->mouseButton.x, \
evt->mouseButton.y});
	else
		hover = mouse_overlap(self, &(sfVector2i){evt->mouseMove.x, \
evt->mouseMove.y});
	if (hover && clicked && evt->mouseButton.button == sfMouseLeft) {
		*(bool *)selected = !*(bool *)selected;
		if (*(bool *)selected)
			self->current_anim = "SELECTED";
		else
			self->current_anim = "IDLE";
	}
}

static void stick_destroy(actor_t *self)
{
	void *selected = fetch_var(self->custom_var, "selected");

	if (!HAS_FAILED(selected))
		free(selected);
	actor_destroy(self);
}

void stick_init(actor_t *actor)
{
	bool *selected = malloc(sizeof(bool));
	anim_t *anim = malloc(sizeof(*anim) * 2);
	sfVector2u size = sfTexture_getSize(\
sfSprite_getTexture(actor->spritesheet));

	actor->rect = (sfIntRect){0, 0, size.x, size.y / 2};
	actor->transform.pos.x += size.x / 2;
	actor->transform.pos.y += size.y / 2;
	actor->transform.scale = (sfVector2f){.4, .2};
	*selected = false;
	add_var(&actor->custom_var, "selected", selected);
	anim[0] = (anim_t){"IDLE", 0, 1, "IDLE"};
	anim[1] = (anim_t){"SELECTED", 1, 1, "SELECTED"};
	actor->anim = anim;
	actor->event = &stick_event;
	actor->render = &stick_render;
	actor->destroy = &stick_destroy;
	actor->current_anim = "IDLE";
}