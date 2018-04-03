/*
** EPITECH PROJECT, 2018
** Game Menu Part
** File description:
** Prefabs for game menu
*/

#include "graph_matchstick.h"

static void howtop_callback(UNUSED actor_t *self)
{
	/* engine_t *engine = fetch_var(self->custom_var, "engine");

	if (!HAS_FAILED(engine))
		engine->active_scene = SCN_HOW2; */
	return;
}

static void play_callback(actor_t *self)
{
	engine_t *engine = fetch_var(self->custom_var, "engine");

	if (!HAS_FAILED(engine))
		engine_changescene(engine, SCN_GAME, true);
}

static void exit_callback(actor_t *self)
{
	engine_t *engine = fetch_var(self->custom_var, "engine");

	if (!HAS_FAILED(engine))
		sfRenderWindow_close(engine->wdw);
}

void add_var_actor(actor_t *howtop, actor_t *play_button, \
actor_t *exit_button, engine_t *engine)
{
	add_var(&(play_button->custom_var), "call_back", &play_callback);
	add_var(&(play_button->custom_var), "engine", engine);
	add_var(&(exit_button->custom_var), "call_back", &exit_callback);
	add_var(&(exit_button->custom_var), "engine", engine);
	add_var(&(howtop->custom_var), "call_back", &howtop_callback);
	add_var(&(howtop->custom_var), "engine", engine);
}

void add_var_exit(actor_t *exit_button, engine_t *engine)
{
	add_var(&(exit_button->custom_var), "call_back", &exit_callback);
	add_var(&(exit_button->custom_var), "engine", engine);
}