/*
** EPITECH PROJECT, 2017
** Cook
** File description:
** Custom button
*/

#include <stdlib.h>
#include "graph_matchstick.h"

static void button_tick(actor_t *self, float dta)
{
	static float anim = .0;

	for (anim += dta; .8 <= anim; anim -= .8)
		update_anim(self);
}

static void button_event(actor_t *self, sfEvent *evt)
{
	bool hover = false;
	bool clicked = evt->type == sfEvtMouseButtonPressed;

	if (clicked)
		hover = mouse_overlap(self, &(sfVector2i){evt->mouseButton.x, \
evt->mouseButton.y});
	else
		hover = mouse_overlap(self, &(sfVector2i){evt->mouseMove.x, \
evt->mouseMove.y});
	if (hover)
		if (clicked && evt->mouseButton.button == sfMouseLeft)
			self->current_anim = "CLICKED";
		else
			self->current_anim = "HOVER";
	else
		self->current_anim = "IDLE";
}

void button_init(actor_t *button)
{
	anim_t *anim = malloc(sizeof(*anim) * 3);
	sfVector2u size = sfTexture_getSize(\
sfSprite_getTexture(button->spritesheet));

	button->rect = (sfIntRect){0, 0, size.x / 2, size.y / 3};
	button->transform.pos.x += size.x / 2;
	button->transform.pos.y += size.y / 2;
	button->tick = &button_tick;
	button->event = &button_event;
	if (!anim)
		return;
	button->anim = anim;
	button->anim[0] = (anim_t){"IDLE", 0, 1, "IDLE"};
	button->anim[1] = (anim_t){"HOVER", 1, 2, "HOVER"};
	button->anim[2] = (anim_t){"CLICKED", 2, 1, "CLICKED"};
}