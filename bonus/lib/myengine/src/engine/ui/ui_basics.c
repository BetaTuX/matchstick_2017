/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** ui basics
*/

#include <stdlib.h>
#include "engine.h"

static bool button_clicked(comp_button_t *self, sfEvent *evt)
{
	sfVector2u size = sfTexture_getSize(sfSprite_getTexture(self->sprite));
	int x = 0;
	int y = 0;
	int left = self->trans.pos.x - (size.x / 2);
	int right = self->trans.pos.x + (size.x / 2);
	int top = self->trans.pos.y - (size.y / 2);
	int bot = self->trans.pos.y + (size.y / 2);

	if (evt->type != sfEvtMouseButtonReleased)
		return (false);
	x = evt->mouseButton.x;
	y = evt->mouseButton.y;
	return (left <= x && x <= right && top <= y && y <= bot);
}

static void ui_event(scene_t *scene, sfEvent *evt)
{
	ui_t *ui = (scene) ? scene->ui : NULL;
	component_t *comp = NULL;

	if (!ui || !scene)
		return;
	for (linked_list_t *cur = ui->components; cur; cur = cur->next) {
		if (cur->data && \
(((component_t *)(cur->data))->type & UI_PAUSE) == scene->gamemode->paused)
			comp = (component_t *)(cur->data);
		else
			comp = NULL;
		if (comp && (comp->type & UI_TYPE) == UI_BUTTON && \
button_clicked((comp_button_t *)comp, evt))
			((comp_button_t *)comp)->callback(\
((comp_button_t *)comp)->data);
	}
}

void ui_destroy(ui_t *ui)
{
	component_t *comp = NULL;

	for (linked_list_t *cur = ui->components; cur; cur = ui->components) {
		comp = (component_t *)(cur->data);
		if (comp)
			comp->destroy(comp);
		ui->components = ui->components->next;
		free(cur);
	}
	free(ui);
}

ui_t *ui_create(void (*init)(ui_t *))
{
	ui_t *ui = malloc(sizeof(*ui));

	if (!ui)
		return (NULL);
	ui->components = NULL;
	ui->event = &ui_event;
	ui->draw = &ui_draw;
	ui->destroy = &ui_destroy;
	if (init)
		init(ui);
	return (ui);
}