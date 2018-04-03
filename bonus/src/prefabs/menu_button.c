/*
** EPITECH PROJECT, 2018
** Menu Button
** File description:
** Prefabs for the Game Menu
*/

#include <stdlib.h>
#include "graph_matchstick.h"

static void menu_button_tick(actor_t *self, UNUSED float dta)
{
	update_anim(self);
}

static void menu_button_event(actor_t *self, sfEvent *evt)
{
	bool hover = false;
	bool clicked = (evt->type == sfEvtMouseButtonPressed);
	void (*call_back)(actor_t *) = fetch_var(self->custom_var, "call_back");

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
	if (my_strcmp("CLICKED", self->current_anim) == 0)
		if (!HAS_FAILED(call_back))
			call_back(self);
}

void init_menu_button(actor_t *button)
{
	anim_t *anim = malloc(sizeof(*anim) * 3);
	sfVector2u size = sfTexture_getSize(\
sfSprite_getTexture(button->spritesheet));

	button->rect = (sfIntRect){0, 0, size.x / 2, size.y / 3};
	button->tick = &menu_button_tick;
	button->event = &menu_button_event;
	if (!anim)
		return;
	button->anim = anim;
	button->anim[0] = (anim_t){"IDLE", 0, 1, "IDLE"};
	button->anim[1] = (anim_t){"HOVER", 1, 1, "HOVER"};
	button->anim[2] = (anim_t){"CLICKED", 2, 1, "CLICKED"};
}