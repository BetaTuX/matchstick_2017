/*
** EPITECH PROJECT, 2018
** engine
** File description:
** component button management
*/

#include <stdlib.h>
#include "engine.h"

static void component_draw(comp_button_t *comp, sfRenderWindow *wdw)
{
	if (!(comp->sprite))
		return;
	sfSprite_setPosition(comp->sprite, comp->trans.pos);
	sfSprite_setScale(comp->sprite, comp->trans.scale);
	sfSprite_setRotation(comp->sprite, comp->trans.rot);
	sfRenderWindow_drawSprite(wdw, comp->sprite, NULL);
}

static void component_destroy(comp_button_t *comp)
{
	free(comp->name);
	if (comp->sprite)
		sfSprite_destroy(comp->sprite);
	free(comp);
}

static int init_sprite(comp_button_t *button, sfTexture *tex)
{
	sfVector2u vec = sfTexture_getSize(tex);

	button->sprite = sfSprite_create();
	if (!(button->sprite))
		return (1);
	sfSprite_setTexture(button->sprite, tex, false);
	sfSprite_setTextureRect(button->sprite, \
(sfIntRect){0, 0, vec.x, vec.y});
	sfSprite_setOrigin(button->sprite, (sfVector2f){vec.x / 2, vec.y / 2});
	return (0);
}

comp_button_t *component_create_button(char *name, void *data, sfTexture *tex, \
void (*callback)(void *))
{
	comp_button_t *comp = malloc(sizeof(*comp));

	if (!comp || !tex)
		return (NULL);
	comp->name = my_strdup(name);
	if (init_sprite(comp, tex))
		return (NULL);
	comp->trans = (transform_t){{.0, .0}, {1.0, 1.0}, .0};
	if (data && callback) {
		comp->data = data;
		comp->callback = callback;
	} else {
		comp->data = NULL;
		comp->callback = NULL;
	}
	comp->type = UI_BUTTON | UI_PAUSE;
	comp->draw = &component_draw;
	comp->destroy = &component_destroy;
	return (comp);
}