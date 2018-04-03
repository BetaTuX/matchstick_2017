/*
** EPITECH PROJECT, 2017
** engine
** File description:
** scene manager
*/

#include <stdlib.h>
#include "engine.h"

static void scene_destroy(scene_t *scene)
{
	actor_t *act = NULL;

	for (linked_list_t *cur = NULL; scene->actors; ) {
		cur = scene->actors;
		scene->actors = scene->actors->next;
		act = (actor_t *)cur->data;
		act->destroy(act);
		free(cur);
	}
	scene->gamemode->destroy(scene->gamemode);
	scene->ui->destroy(scene->ui);
	free(scene);
}

int scene_add(engine_t *engine, char *name, gamemode_t *gm, ui_t *ui)
{
	scene_t *scene = (gm && ui && name) ? malloc(sizeof(*scene)) : NULL;

	if (!scene)
		return (-1);
	scene->actors = NULL;
	scene->gamemode = gm;
	scene->ui = ui;
	scene->bg_music = NULL;
	scene->pauseable = true;
	scene->tick = &scene_tick;
	scene->event = &scene_event;
	scene->render = &scene_render;
	scene->destroy = &scene_destroy;
	add_var(&(engine->scenes), name, scene);
	return (0);
}

int scene_remove(engine_t *engine, char *name)
{
	scene_t *scene = scene_fetch(engine, name);

	if (HAS_FAILED(scene))
		return (-1);
	scene->destroy(scene);
	return (0);
}

scene_t *scene_fetch(engine_t *engine, const char *name)
{
	return (fetch_var(engine->scenes, name));
}