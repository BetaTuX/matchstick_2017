/*
** EPITECH PROJECT, 2018
** actor
** File description:
** 2017
*/

#include <stdlib.h>
#include "engine.h"

static void init_actor(actor_t *actor, char *name, sfTexture *tex)
{
	sfVector2u vec = sfTexture_getSize(tex);

	actor->name = my_strdup(name);
	actor->collision_layer = my_strdup("");
	actor->spritesheet = sfSprite_create();
	sfSprite_setTexture(actor->spritesheet, tex, false);
	actor->rect = (sfIntRect){0, 0, vec.x, vec.y};
	actor->transform = (transform_t){(sfVector2f){.0, .0},\
(sfVector2f){1.0, 1.0}, .0};
	actor->anim = (anim_t [1]){(anim_t){"IDLE", 0, 1, "IDLE"}};
	actor->current_anim = "IDLE";
	actor->custom_var = NULL;
}

void actor_destroy(actor_t *actor)
{
	sfSprite_destroy(actor->spritesheet);
	free(actor->name);
	free(actor->collision_layer);
	free(actor);
}

actor_t *actor_create(char *name, sfTexture *tex, void (*init)(actor_t *))
{
	actor_t *actor = malloc(sizeof(*actor));

	if (!(actor && tex))
		return (NULL);
	init_actor(actor, name, tex);
	actor->event = &actor_event;
	actor->overlap = &actor_overlap;
	actor->tick = &actor_tick;
	actor->render = &actor_render;
	actor->destroy = &actor_destroy;
	if (init)
		init(actor);
	return (actor);
}