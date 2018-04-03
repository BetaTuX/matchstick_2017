/*
** EPITECH PROJECT, 2018
** Engine
** File description:
** 2017
*/

#include <stdlib.h>
#include "engine.h"

static void destroy_dict(linked_dict_t *dict, void (*fx)(void *))
{
	for (linked_dict_t *cur = dict; cur; cur = cur->next)
		fx((((void **)(cur->data))[1]));
	destroy_varlist(dict);
}

static void engine_destroy(engine_t *engine)
{
	destroy_dict(engine->textures, (void (*)(void *))&sfTexture_destroy);
	destroy_dict(engine->sounds, (void (*)(void *))&sfMusic_destroy);
	destroy_dict(engine->fonts, (void (*)(void *))&sfFont_destroy);
	for (linked_dict_t *cur = engine->scenes; cur; cur = cur->next)
		((scene_t *)(((void **)(cur->data))[1]))->destroy(\
(scene_t *)(((void **)(cur->data))[1]));
	destroy_varlist(engine->scenes);
	destroy_varlist(engine->custom_var);
	sfRenderWindow_destroy(engine->wdw);
	free(engine);
}

engine_t *engine_create(sfRenderWindow * wdw)
{
	engine_t *engine = malloc(sizeof(*engine));

	engine->wdw = wdw;
	engine->active_scene = "none";
	engine->textures= NULL;
	engine->fonts= NULL;
	engine->sounds= NULL;
	engine->scenes= NULL;
	engine->custom_var= NULL;
	engine->run = &engine_run;
	engine->poll_event = &engine_pollevent;
	engine->tick = &engine_tick;
	engine->render = &engine_render;
	engine->destroy = &engine_destroy;
	if (scene_add(engine, "none", gamemode_create(NULL), ui_create(NULL)) \
== -1) {
		engine->destroy(engine);
		return (NULL);
	}
	return (engine);
}