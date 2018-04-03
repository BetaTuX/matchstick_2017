/*
** EPITECH PROJECT, 2018
** my engine
** File description:
** ui draw fx
*/

#include "engine.h"

void ui_draw(scene_t *scene, sfRenderWindow *wdw)
{
	ui_t *ui = (scene) ? scene->ui : NULL;
	component_t *comp = NULL;

	if (!ui || !wdw || !scene)
		return;
	for (linked_list_t *cur = ui->components; cur; cur = cur->next) {
		if (cur->data && \
(((component_t *)(cur->data))->type & 0b1) == scene->gamemode->paused)
			comp = (component_t *)(cur->data);
		else
			comp = NULL;
		if (comp && comp->draw)
			comp->draw(comp, wdw);
	}
}