/*
** EPITECH PROJECT, 2018
** CSFML engine
** File description:
** components management (create, destroy...)
*/

#include <stdlib.h>
#include "engine.h"

static void component_draw(comp_label_t *comp, sfRenderWindow *wdw)
{
	char *data_str = NULL;
	char *str = NULL;

	if (comp->data)
		data_str = comp->data_to_str(comp->data);
	else
		data_str = my_strdup("none");
	if (data_str) {
		str = my_strcat(my_strdup(comp->name), data_str);
		if (comp->text) {
			sfText_setPosition(comp->text, comp->trans.pos);
			sfText_setString(comp->text, str);
			sfRenderWindow_drawText(wdw, comp->text, NULL);
		}
		free(str);
	}
	free(data_str);
}

static void component_destroy(comp_label_t *comp)
{
	free(comp->name);
	if (comp->text)
		sfText_destroy(comp->text);
	free(comp);
}

comp_label_t *component_create_label(char *name, void *data, \
sfFont *font, char *(*data_to_str)(void *))
{
	comp_label_t *comp = malloc(sizeof(*comp));

	if (!comp || !font || !data_to_str) {
		free(comp);
		return (NULL);
	}
	comp->name = my_strdup(name);
	comp->text = sfText_create();
	comp->trans = (transform_t){{.0, .0}, {1.0, 1.0}, .0};
	sfText_setFont(comp->text, font);
	sfText_setColor(comp->text, sfBlack);
	if (!(comp->name) || !(comp->text)) {
		component_destroy(comp);
		return (NULL);
	}
	comp->data = data;
	comp->data_to_str = data_to_str;
	comp->type = UI_LABEL;
	comp->draw = &component_draw;
	comp->destroy = &component_destroy;
	return (comp);
}