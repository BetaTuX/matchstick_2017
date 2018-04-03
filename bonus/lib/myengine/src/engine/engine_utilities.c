/*
** EPITECH PROJECT, 2018
** Runner 2017
** File description:
** Engine utilities
*/

#include "engine.h"

void engine_render(engine_t *engine)
{
	scene_t *scene = scene_fetch(engine, engine->active_scene);

	sfRenderWindow_clear(engine->wdw, sfWhite);
	if (HAS_FAILED(scene))
		return;
	scene->render(scene, engine->wdw);
	sfRenderWindow_display(engine->wdw);
}

void engine_tick(engine_t *engine, float dta)
{
	scene_t *scene = scene_fetch(engine, engine->active_scene);

	if (HAS_FAILED(scene))
		return;
	scene->tick(scene, dta);
}

static void scene_managemusic(engine_t *engine, scene_t *next_scene)
{
	scene_t *act_scn = scene_fetch(engine, engine->active_scene);

	if (HAS_FAILED(act_scn))
		return;
	if (act_scn->bg_music)
		sfMusic_stop(act_scn->bg_music);
	if (next_scene->bg_music)
		sfMusic_play(next_scene->bg_music);
}

int engine_changescene(engine_t *engine, const char *scene_name, bool reset)
{
	scene_t *scene = scene_fetch(engine, scene_name);
	void (*reset_fx)(scene_t *) = NULL;

	if (!HAS_FAILED(scene)) {
		scene_managemusic(engine, scene);
		if (reset)
			reset_fx = (void (*)(scene_t *))fetch_var(\
scene->gamemode->var, "reset_fx");
		if (!(HAS_FAILED(reset_fx) || !reset_fx))
			reset_fx(scene);
		engine->active_scene = (char *)scene_name;
		return (0);
	} else
		return (1);
}