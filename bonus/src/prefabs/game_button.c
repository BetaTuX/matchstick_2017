/*
** EPITECH PROJECT, 2018
** game Button
** File description:
** Prefabs for game Button
*/

#include "graph_matchstick.h"

static void game_button_event(actor_t *self, sfEvent *evt)
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

void init_game_button(actor_t *button)
{
	sfVector2u size = sfTexture_getSize(\
sfSprite_getTexture(button->spritesheet));

	button->rect = (sfIntRect){0, 0, size.x, size.y};
	button->event = &game_button_event;
}